const HOST = "com.adilsukumar.dsa_sync";
const ALARM = "dsa-nightly-sync";

async function scheduleNightly() {
  const now = new Date();
  const next = new Date(now);
  next.setHours(23, 45, 0, 0);
  if (next <= now) next.setDate(next.getDate() + 1);
  await chrome.alarms.clear(ALARM);
  chrome.alarms.create(ALARM, { when: next.getTime(), periodInMinutes: 24 * 60 });
  await chrome.storage.local.set({ nextRun: next.toISOString() });
}

async function getSession() {
  const cookie = await chrome.cookies.get({ url: "https://leetcode.com/", name: "LEETCODE_SESSION" });
  if (!cookie?.value) throw new Error("Log in to LeetCode in Chrome first.");
  return cookie.value;
}

async function syncNow(source = "manual") {
  const session = await getSession();
  await chrome.storage.local.set({ status: "Sync running…", lastSource: source });
  const response = await chrome.runtime.sendNativeMessage(HOST, {
    action: "sync", leetcodeSession: session
  });
  if (!response?.ok) throw new Error(response?.error || "Local sync failed.");
  await chrome.storage.local.set({
    status: "Last sync succeeded", lastRun: new Date().toISOString(), summary: response.summary
  });
  return response;
}

chrome.runtime.onInstalled.addListener(scheduleNightly);
chrome.runtime.onStartup.addListener(scheduleNightly);
chrome.alarms.onAlarm.addListener((alarm) => {
  if (alarm.name === ALARM) syncNow("scheduled").catch(async (error) => {
    await chrome.storage.local.set({ status: "Sync failed: " + error.message });
  });
});
chrome.runtime.onMessage.addListener((message, _sender, sendResponse) => {
  if (message?.action !== "sync") return;
  syncNow("manual").then(sendResponse).catch((error) => sendResponse({ ok: false, error: error.message }));
  return true;
});

scheduleNightly();

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

async function catchUpIfNeeded() {
  const now = new Date();
  if (now.getHours() < 23 || (now.getHours() === 23 && now.getMinutes() < 45)) return;
  const { lastRun } = await chrome.storage.local.get("lastRun");
  if (lastRun && new Date(lastRun).toDateString() === now.toDateString()) return;
  await syncNow("catch-up");
}

async function initialize() {
  await scheduleNightly();
  await catchUpIfNeeded();
}

async function getSession() {
  const cookie = await chrome.cookies.get({ url: "https://leetcode.com/", name: "LEETCODE_SESSION" });
  if (!cookie?.value) throw new Error("Log in to LeetCode in Chrome first.");
  return cookie.value;
}

async function getCodeChefCookies() {
  const cookies = await chrome.cookies.getAll({ domain: ".codechef.com" });
  return cookies.map((cookie) => cookie.name + "=" + cookie.value).join("; ");
}

async function syncNow(source = "manual", fullHistory = false) {
  const session = await getSession();
  const codechefCookies = await getCodeChefCookies();
  await chrome.storage.local.set({ status: "Sync running…", lastSource: source });
  const response = await chrome.runtime.sendNativeMessage("com.adilsukumar.dsasync", {
    action: fullHistory ? "fullSync" : "sync",
    leetcodeSession: session,
    codechefCookies
  });
  if (!response || !response.ok) {
    const err = (response && response.error) ? response.error : (chrome.runtime.lastError ? chrome.runtime.lastError.message : "Native sync failed.");
    throw new Error(err);
  }
  await chrome.storage.local.set({
    status: "Last sync succeeded", lastRun: new Date().toISOString(), summary: response.summary
  });
  return response;
}

chrome.runtime.onInstalled.addListener(() => initialize().catch(() => {}));
chrome.runtime.onStartup.addListener(() => initialize().catch(() => {}));
chrome.alarms.onAlarm.addListener((alarm) => {
  if (alarm.name === ALARM) syncNow("scheduled").catch(async (error) => {
    await chrome.storage.local.set({ status: "Sync failed: " + error.message });
  });
});
chrome.runtime.onMessage.addListener((message, _sender, sendResponse) => {
  if (message?.action !== "sync" && message?.action !== "fullSync") return;
  const fullHistory = message.action === "fullSync";
  syncNow(fullHistory ? "full-history" : "manual", fullHistory).then(sendResponse).catch(async (error) => {
    const status = "Sync failed: " + error.message;
    await chrome.storage.local.set({ status });
    sendResponse({ ok: false, error: error.message });
  });
  return true;
});

initialize().catch(() => {});

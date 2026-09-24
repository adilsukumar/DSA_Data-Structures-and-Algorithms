const button = document.querySelector("#sync");
const fullButton = document.querySelector("#full-sync");
const status = document.querySelector("#status");

chrome.storage.local.get(["status", "lastRun"], (data) => {
  status.textContent = data.status || "Ready.";
  if (data.lastRun) status.textContent += "\n" + new Date(data.lastRun).toLocaleString();
});

function startSync(action, message) {
  button.disabled = true;
  fullButton.disabled = true;
  status.textContent = message;
  chrome.runtime.sendMessage({ action }, (response) => {
    button.disabled = false;
    fullButton.disabled = false;
    if (chrome.runtime.lastError) {
      status.textContent = "Sync failed: " + chrome.runtime.lastError.message;
    } else if (!response?.ok) {
      status.textContent = "Sync failed: " + (response?.error || "unknown error");
    } else {
      status.textContent = "Sync complete. " + (response.summary || "");
    }
  });
}

button.addEventListener("click", () => {
  startSync("sync", "Sync running…");
});

fullButton.addEventListener("click", () => {
  startSync("fullSync", "Full history backfill running; this can take several minutes…");
});

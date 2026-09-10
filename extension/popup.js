const button = document.querySelector("#sync");
const status = document.querySelector("#status");

chrome.storage.local.get(["status", "lastRun"], (data) => {
  status.textContent = data.status || "Ready.";
  if (data.lastRun) status.textContent += "\n" + new Date(data.lastRun).toLocaleString();
});

button.addEventListener("click", () => {
  button.disabled = true;
  status.textContent = "Sync running…";
  chrome.runtime.sendMessage({ action: "sync" }, (response) => {
    button.disabled = false;
    if (chrome.runtime.lastError) {
      status.textContent = "Sync failed: " + chrome.runtime.lastError.message;
    } else if (!response?.ok) {
      status.textContent = "Sync failed: " + (response?.error || "unknown error");
    } else {
      status.textContent = "Sync complete. " + (response.summary || "");
    }
  });
});

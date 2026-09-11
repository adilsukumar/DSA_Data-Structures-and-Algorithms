# DSA Submission Sync extension

This Manifest V3 extension reads the current LeetCode login from Chrome and
passes it in memory to a loopback helper listening only on `127.0.0.1`. The
helper runs the model-free import, organization, statistics, commit, and push
pipeline. The login token is never written to the repository.

Run `scripts/setup_chrome_extension.ps1` once. It creates a private local token
and starts the loopback helper at Windows login. Then load this directory as an
unpacked extension from `chrome://extensions`.

Use **Sync now** whenever needed. The extension also schedules a daily sync at
11:45 PM local time. If Chrome was closed then, opening it later that night
triggers a catch-up sync.

Routine syncs scan the newest five CodeChef history pages (about 100 recent
submissions). The standalone importer still supports a full historical scan.

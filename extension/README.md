# DSA Submission Sync extension

This Manifest V3 extension reads the current LeetCode login from Chrome and
passes it in memory to the repository's local native-messaging helper. The
helper runs the model-free import, organization, statistics, commit, and push
pipeline. The login token is never written to the repository.

Run `scripts/setup_chrome_extension.ps1` once, then load this directory as an
unpacked extension from `chrome://extensions`.

Use **Sync now** whenever needed. The extension also schedules a daily sync at
11:45 PM local time; Chrome must be running for the alarm to fire on time.

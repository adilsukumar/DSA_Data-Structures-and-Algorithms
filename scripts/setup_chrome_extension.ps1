[CmdletBinding()]
param()

$ErrorActionPreference = "Stop"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$ExtensionDir = Join-Path $RepoRoot "extension"
$BridgeScript = Join-Path $PSScriptRoot "extension_bridge.py"
$BridgeDir = Join-Path $env:LOCALAPPDATA "DSAExtension"
$LegacyTokenFile = Join-Path $BridgeDir "bridge.token"
$TokenFile = Join-Path $ExtensionDir "bridge.token"
$ConfigFile = Join-Path $ExtensionDir "config.local.js"
$TaskName = "DSA-Extension-Bridge"
$LegacyTaskName = "DSA-Daily-Solution-Sweep"

New-Item -ItemType Directory -Force -Path $BridgeDir | Out-Null

if (Test-Path -LiteralPath $TokenFile) {
    $token = (Get-Content -LiteralPath $TokenFile -Raw).Trim()
}
elseif (Test-Path -LiteralPath $LegacyTokenFile) {
    $token = (Get-Content -LiteralPath $LegacyTokenFile -Raw).Trim()
}
else {
    $bytes = New-Object byte[] 32
    [Security.Cryptography.RandomNumberGenerator]::Create().GetBytes($bytes)
    $token = [Convert]::ToBase64String($bytes).TrimEnd('=').Replace('+', '-').Replace('/', '_')
}
$utf8 = [Text.UTF8Encoding]::new($false)
[IO.File]::WriteAllText($TokenFile, $token, $utf8)
[IO.File]::WriteAllText($ConfigFile, "self.DSA_BRIDGE_TOKEN = `"$token`";`n", $utf8)

$python = (Get-Command python -ErrorAction Stop).Source
$pythonw = Join-Path (Split-Path -Parent $python) "pythonw.exe"
if (-not (Test-Path -LiteralPath $pythonw)) {
    $pythonw = $python
}

$existing = Get-ScheduledTask -TaskName $TaskName -ErrorAction SilentlyContinue
if ($existing) {
    Stop-ScheduledTask -TaskName $TaskName -ErrorAction SilentlyContinue
    Unregister-ScheduledTask -TaskName $TaskName -Confirm:$false
}

$action = New-ScheduledTaskAction `
    -Execute $pythonw `
    -Argument "`"$BridgeScript`"" `
    -WorkingDirectory $RepoRoot
$trigger = New-ScheduledTaskTrigger `
    -AtLogOn `
    -User "$env:USERDOMAIN\$env:USERNAME"
$settings = New-ScheduledTaskSettingsSet `
    -AllowStartIfOnBatteries `
    -DontStopIfGoingOnBatteries `
    -MultipleInstances IgnoreNew `
    -RestartCount 3 `
    -RestartInterval (New-TimeSpan -Minutes 1)
$principal = New-ScheduledTaskPrincipal `
    -UserId "$env:USERDOMAIN\$env:USERNAME" `
    -LogonType Interactive `
    -RunLevel Limited

Register-ScheduledTask `
    -TaskName $TaskName `
    -Action $action `
    -Trigger $trigger `
    -Settings $settings `
    -Principal $principal `
    -Description "Local loopback bridge for the DSA Submission Sync Chrome extension." `
    -Force | Out-Null
Start-ScheduledTask -TaskName $TaskName
Start-Sleep -Seconds 2

# The extension owns the nightly schedule now. Keep the old task installed but
# disabled so it cannot run with an expired cookie and produce duplicate errors.
$legacyTask = Get-ScheduledTask -TaskName $LegacyTaskName -ErrorAction SilentlyContinue
if ($legacyTask) {
    Stop-ScheduledTask -TaskName $LegacyTaskName -ErrorAction SilentlyContinue
    Disable-ScheduledTask -TaskName $LegacyTaskName | Out-Null
}

$health = Invoke-RestMethod -Uri "http://127.0.0.1:8765/health" -TimeoutSec 5
if (-not $health.ok) {
    throw "The extension bridge did not pass its health check."
}

Write-Host "DSA extension bridge is running." -ForegroundColor Green
Write-Host "Health check: http://127.0.0.1:8765/health"
Write-Host "Extension folder: $ExtensionDir"
if ($legacyTask) {
    Write-Host "Disabled obsolete task: $LegacyTaskName"
}
Write-Host "Reload the extension once at chrome://extensions, then click Sync now."

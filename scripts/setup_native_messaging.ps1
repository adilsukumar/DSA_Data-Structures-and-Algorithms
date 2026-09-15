<#
.SYNOPSIS
    Registers the Chrome Native Messaging host and removes the old Task Scheduler bridge.
#>

[CmdletBinding()]
param(
    [switch]$Remove
)

$ErrorActionPreference = "Stop"

$HostName = "com.adilsukumar.dsasync"
$ExtensionId = "plbilacillelljfdjbkhhmkofghlfajl"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$Script = Join-Path $RepoRoot "scripts\native_host.py"
$BatPath = Join-Path $RepoRoot "scripts\native_host.bat"
$ManifestPath = Join-Path $RepoRoot "scripts\native_messaging_host.json"

$RegistryPath = "HKCU:\Software\Google\Chrome\NativeMessagingHosts\$HostName"

# ---------------------------------------------------------------- remove ----
if ($Remove) {
    if (Test-Path $RegistryPath) {
        Remove-Item $RegistryPath -Recurse -Force
        Write-Host "Removed registry key for native messaging host." -ForegroundColor Yellow
    }
    return
}

# --------------------------------------------------------------- checks ----
$python = (Get-Command python -ErrorAction SilentlyContinue).Source
if (-not $python) {
    $python = (Get-Command py -ErrorAction SilentlyContinue).Source
}
if (-not $python) {
    throw "Python is not on PATH. Install it, or edit this script to hard-code the path."
}

# ------------------------------------------------------------- setup ----

# 1. Generate the .bat wrapper
$BatContent = "@echo off`nset PYTHONIOENCODING=utf-8`n`"$python`" `"$Script`" %*"
Set-Content -Path $BatPath -Value $BatContent -Encoding ASCII

# 2. Generate the JSON manifest
# The path must be absolute and point to the .bat wrapper
# We must double escape backslashes in JSON
$EscapedBatPath = $BatPath -replace '\\', '\\'
$ManifestContent = @"
{
  "name": "$HostName",
  "description": "DSA Sync Native Messaging Host",
  "path": "$EscapedBatPath",
  "type": "stdio",
  "allowed_origins": [
    "chrome-extension://$ExtensionId/"
  ]
}
"@
Set-Content -Path $ManifestPath -Value $ManifestContent -Encoding ASCII

# 3. Register in Windows Registry
if (-not (Test-Path "HKCU:\Software\Google\Chrome\NativeMessagingHosts")) {
    New-Item "HKCU:\Software\Google\Chrome\NativeMessagingHosts" -Force | Out-Null
}
New-Item -Path $RegistryPath -Force | Out-Null
Set-ItemProperty -Path $RegistryPath -Name "(default)" -Value $ManifestPath

Write-Host "Successfully registered Chrome Native Messaging host: $HostName" -ForegroundColor Green

# 4. Remove old scheduled task if it exists
$OldTaskName = "DSA-Extension-Bridge"
$existing = Get-ScheduledTask -TaskName $OldTaskName -ErrorAction SilentlyContinue
if ($existing) {
    Unregister-ScheduledTask -TaskName $OldTaskName -Confirm:$false
    Write-Host "Cleaned up old scheduled task '$OldTaskName'." -ForegroundColor Yellow
}

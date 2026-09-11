[CmdletBinding()]
param()

$ErrorActionPreference = "Stop"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$HostLauncher = Join-Path $PSScriptRoot "extension_native_host.cmd"
$HostDir = Join-Path $env:LOCALAPPDATA "DSAExtension"
$HostManifest = Join-Path $HostDir "com.adilsukumar.dsa_sync.json"
$ExtensionId = "plbilacillelljfdjbkhhmkofghlfajl"

New-Item -ItemType Directory -Force -Path $HostDir | Out-Null
$manifest = @{
    name = "com.adilsukumar.dsa_sync"
    description = "Local bridge for the DSA submission sync extension"
    path = $HostLauncher
    type = "stdio"
    allowed_origins = @("chrome-extension://$ExtensionId/")
} | ConvertTo-Json -Depth 4
# Windows PowerShell 5.1's `-Encoding UTF8` adds a BOM. Chrome rejects a
# native-host manifest when any bytes appear before its opening `{`.
[System.IO.File]::WriteAllText(
    $HostManifest,
    $manifest,
    [System.Text.UTF8Encoding]::new($false)
)

$key = "HKCU:\Software\Google\Chrome\NativeMessagingHosts\com.adilsukumar.dsa_sync"
New-Item -Force -Path $key | Out-Null
Set-Item -Path $key -Value $HostManifest

Write-Host "Native host registered." -ForegroundColor Green
Write-Host "Extension folder: $(Join-Path $RepoRoot 'extension')"
Write-Host "Extension ID: $ExtensionId"
Write-Host "Now open chrome://extensions, enable Developer mode, and choose Load unpacked."

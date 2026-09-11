[CmdletBinding()]
param()

$ErrorActionPreference = "Stop"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$HostScript = Join-Path $PSScriptRoot "extension_native_host.py"
$HostDir = Join-Path $env:LOCALAPPDATA "DSAExtension"
$HostLauncher = Join-Path $HostDir "dsa_native_host.exe"
$HostManifest = Join-Path $HostDir "com.adilsukumar.dsa_sync.json"
$ExtensionId = "plbilacillelljfdjbkhhmkofghlfajl"

New-Item -ItemType Directory -Force -Path $HostDir | Out-Null
$python = (Get-Command python -ErrorAction Stop).Source
$escapedPython = $python.Replace('\', '\\').Replace('"', '\"')
$escapedScript = $HostScript.Replace('\', '\\').Replace('"', '\"')
$source = @"
using System;
using System.Diagnostics;
using System.IO;

public static class DsaNativeLauncher {
    private static byte[] ReadExact(Stream stream, int count) {
        var data = new byte[count];
        var offset = 0;
        while (offset < count) {
            var read = stream.Read(data, offset, count - offset);
            if (read == 0) throw new EndOfStreamException();
            offset += read;
        }
        return data;
    }

    public static int Main() {
        var chromeIn = Console.OpenStandardInput();
        var length = ReadExact(chromeIn, 4);
        var payload = ReadExact(chromeIn, BitConverter.ToInt32(length, 0));
        var start = new ProcessStartInfo("$escapedPython", "\"$escapedScript\"");
        start.UseShellExecute = false;
        start.CreateNoWindow = true;
        start.RedirectStandardInput = true;
        start.RedirectStandardOutput = true;
        start.RedirectStandardError = true;
        using (var child = Process.Start(start)) {
            child.StandardInput.BaseStream.Write(length, 0, length.Length);
            child.StandardInput.BaseStream.Write(payload, 0, payload.Length);
            child.StandardInput.Close();
            child.StandardOutput.BaseStream.CopyTo(Console.OpenStandardOutput());
            child.WaitForExit();
            return child.ExitCode;
        }
    }
}
"@
if (Test-Path -LiteralPath $HostLauncher) {
    Remove-Item -LiteralPath $HostLauncher -Force
}
Add-Type -TypeDefinition $source -OutputAssembly $HostLauncher `
    -OutputType ConsoleApplication -ReferencedAssemblies @("System.dll", "System.Core.dll")

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
Write-Host "Native executable: $HostLauncher"
Write-Host "Extension folder: $(Join-Path $RepoRoot 'extension')"
Write-Host "Extension ID: $ExtensionId"
Write-Host "Now open chrome://extensions, enable Developer mode, and choose Load unpacked."

<#
.SYNOPSIS
    Registers (or removes) the nightly DSA website sync in Windows Task Scheduler.

.DESCRIPTION
    Creates a scheduled task that runs scripts/daily_sync.py once a day. It first
    imports new submissions from LeetCode and CodeChef, archives unsuccessful
    attempts, explains accepted solutions, rebuilds the index and stats, and
    commits and pushes as you.

    The task runs as the CURRENT USER and only while you are logged on. That is
    deliberate: `claude -p` needs your Claude Code credentials, and `git push`
    needs your stored Git credentials. Neither is available to a task running
    under SYSTEM or in a logged-off session.

    StartWhenAvailable is enabled, so if the machine is asleep or off at the
    scheduled time, the sweep runs at the next opportunity instead of being
    skipped.

.PARAMETER Time
    24-hour local time to run, as HH:mm. Default 23:45.

.PARAMETER Remove
    Unregister the task instead of creating it.

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\setup_daily_task.ps1
    powershell -ExecutionPolicy Bypass -File scripts\setup_daily_task.ps1 -Time 23:45
    powershell -ExecutionPolicy Bypass -File scripts\setup_daily_task.ps1 -Remove
#>

[CmdletBinding()]
param(
    [string]$Time = "23:45",
    [switch]$Remove
)

$ErrorActionPreference = "Stop"

$TaskName = "DSA-Daily-Solution-Sweep"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$Script   = Join-Path $RepoRoot "scripts\daily_sync.py"

# ---------------------------------------------------------------- remove ----
if ($Remove) {
    $existing = Get-ScheduledTask -TaskName $TaskName -ErrorAction SilentlyContinue
    if ($existing) {
        Unregister-ScheduledTask -TaskName $TaskName -Confirm:$false
        Write-Host "Removed scheduled task '$TaskName'." -ForegroundColor Yellow
    }
    else {
        Write-Host "No task named '$TaskName' was registered." -ForegroundColor Yellow
    }
    return
}

# --------------------------------------------------------------- checks ----
if (-not (Test-Path $Script)) {
    throw "Cannot find $Script -- run this from inside the repo."
}

$python = (Get-Command python -ErrorAction SilentlyContinue).Source
if (-not $python) {
    $python = (Get-Command py -ErrorAction SilentlyContinue).Source
}
if (-not $python) {
    throw "Python is not on PATH. Install it, or edit this script to hard-code the path."
}

if (-not (Get-Command claude -ErrorAction SilentlyContinue)) {
    Write-Warning "The 'claude' CLI is not on PATH. The sweep will file nothing until it is."
}

try {
    $when = [datetime]::ParseExact($Time, "HH:mm", $null)
}
catch {
    throw "Could not read -Time '$Time'. Use 24-hour HH:mm, for example 21:00."
}

# ------------------------------------------------------------- register ----
$action = New-ScheduledTaskAction `
    -Execute $python `
    -Argument "`"$Script`"" `
    -WorkingDirectory $RepoRoot

$trigger = New-ScheduledTaskTrigger -Daily -At $when

$settings = New-ScheduledTaskSettingsSet `
    -StartWhenAvailable `
    -DontStopIfGoingOnBatteries `
    -AllowStartIfOnBatteries `
    -ExecutionTimeLimit (New-TimeSpan -Hours 1) `
    -MultipleInstances IgnoreNew

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
    -Description "Archives attempts and imports, explains, indexes, commits and pushes LeetCode and CodeChef solutions." `
    -Force | Out-Null

Write-Host ""
Write-Host "Registered '$TaskName'" -ForegroundColor Green
Write-Host "  runs      : daily at $Time (catches up if the PC was off)"
Write-Host "  command   : $python `"$Script`""
Write-Host "  workdir   : $RepoRoot"
Write-Host ""
Write-Host "Run it right now to check it works:" -ForegroundColor Cyan
Write-Host "  Start-ScheduledTask -TaskName '$TaskName'"
Write-Host ""
Write-Host "Inspect or change it:" -ForegroundColor Cyan
Write-Host "  Get-ScheduledTask -TaskName '$TaskName' | Get-ScheduledTaskInfo"
Write-Host "  taskschd.msc"
Write-Host ""
Write-Host "Remove it:" -ForegroundColor Cyan
Write-Host "  powershell -ExecutionPolicy Bypass -File scripts\setup_daily_task.ps1 -Remove"

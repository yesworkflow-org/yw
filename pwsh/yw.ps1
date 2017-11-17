#!/usr/bin/env pwsh

Param(
	[switch] $windows, [switch] $linux, [switch] $macos,
	[switch] $x86,     [switch] $x64,
	[switch] $debug,   [switch] $release,
	[switch] $verbose,
	[switch] $time,
	[switch] $benchmark
)

# work in the directory containing this script
$MyInvocation.MyCommand.Path | Split-Path -Parent | Push-Location

# load utility functions
. ./utilities.ps1

Pop-Location

$repoRoot = Get-YWRepositoryRoot

if ($windows) {
	$os = 'Windows'
} elseif ($linux) {
	$os = "Linux"
} elseif ($macos) {
	$os = "MacOS"
} else {
	$os = Get-RuntimePlatform
}

if ($x86) {
	$platform = 'x86'
} else {
	$platform = 'x64'
}

if ($debug) {
	$build = "Debug"
} else {
	$build = "Release"
}

try {
	$yw = Get-YesWorkflowExe -repoRoot $repoRoot -os $os -platform $platform `
								-build $build
} catch {
	Write-Host -ForegroundColor red $("ERROR: $_"); exit
}

$scriptBlock = [Scriptblock]::Create("$yw $args")

if ($verbose) {
	Write-Host -ForegroundColor green "YW platform  : $os"
	Write-Host -ForegroundColor green "YW executable: $yw"
	Write-Host -ForegroundColor green "YW command   : $scriptBlock"
}

if ($benchmark) {
	$iterations = 100;
	$totalTime = 0 
	for ($i = 0; $i -le $iterations; $i++) {
		$timeRecord = Measure-Command { $ywOutputs = Invoke-Command -ScriptBlock $scriptBlock }
		if ($i -gt 0) { $totalTime += $timeRecord | Select-Object -ExpandProperty TotalSeconds }
	}
} else {
	$iterations = 1;
	$timeRecord = Measure-Command { $ywOutputs = Invoke-Command -ScriptBlock $scriptBlock }
	$totalTime += $timeRecord | Select-Object -ExpandProperty TotalSeconds
}

$ywOutputs

if ($time) {
	$totalTime
	$averageTime = $totalTime/$iterations
	 Write-Host -ForegroundColor green  "`nYW execution time: ${averageTime}s"
}

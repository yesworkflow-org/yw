#!/usr/bin/env pwsh

[cmdletbinding()]
Param(
	[ValidateSet('Windows','MacOS','Linux')] [string] $os       = $null,
	[ValidateSet('x86','x64')]               [string] $platform = 'x64',
	[ValidateSet('Debug','Release')]         [string] $build    = 'Release',
	                                         [string] $exe      = $null
)

# work in the directory containing this script
$MyInvocation.MyCommand.Path | Split-Path -Parent | Set-Location

# load utility functions
. ../../pwsh/utilities.ps1

$repoRoot = Get-YWRepositoryRoot

if (!$os) { $os = Get-RuntimePlatform }

if ($exe) {
	$yw = $exe
} else {
	try {
		$yw = Get-YesWorkflowExe -repoRoot $repoRoot -os $os `
		                          -platform $platform -build $build
	} catch {
		Write-Host -ForegroundColor red $("ERROR: $_.Exception.Message"); exit
	}
}

"YW platform  : $os"
"YW executable: $yw"

& $yw graph simulate_data_collection.py graph.format=DOT graph.file=wf.dot
Find-FirstDiff -actual 'wf.dot' -expected 'expected/wf.dot'
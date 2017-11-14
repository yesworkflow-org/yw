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
"YW platform  : ${os}"

if ($exe) {
	$yw = $exe
} else {
	$yw = Get-YesWorkflowExe -repoRoot $repoRoot -os $os `
							-platform $platform -build $build
}

"YW executable: $yw"

& $yw graph simulate_data_collection.py graph.format=DOT graph.file=wf.dot
Find-FirstDiff -actual 'wf.dot' -expected 'expected/wf.dot'
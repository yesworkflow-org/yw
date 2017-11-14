#!/usr/bin/env pwsh

# work in the directory containing this script
$MyInvocation.MyCommand.Path | Split-Path -Parent | Set-Location

$RepoRoot = '../../'
. $RepoRoot/pwsh/utilities.ps1

$yw = Get-YesWorkflowPath Linux 
& $yw graph simulate_data_collection.py graph.format=DOT graph.file=wf.dot
Find-FirstDiff -actual 'wf.dot' -expected 'expected/wf.dot'
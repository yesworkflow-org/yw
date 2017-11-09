#!/usr/bin/env pwsh

# work in the directory containing this script
$MyInvocation.MyCommand.Path | Split-Path -Parent | Set-Location

# Generate the C++ parser classes for the grammar
antlr4.ps1 -Dlanguage=Cpp -package yw YW_CONFIG_.g4

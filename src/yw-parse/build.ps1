#!/usr/bin/env pwsh

# work in the directory containing this script
$MyInvocation.MyCommand.Path | Split-Path -Parent | Set-Location

# Generate the C++ parser classes for the grammar in YW.g4
java -jar $Env:ANTLR4_JAR -Dlanguage=Cpp -package yw YW.g4
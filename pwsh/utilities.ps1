
function Get-YWRepositoryRoot {
    $MyInvocation.MyCommand.ScriptBlock.File | Split-Path -Parent | Split-Path -Parent
}

function Get-RuntimePlatform {
    if ($IsWindows) { 'Windows' } 
    elseif ($IsMacOS) { 'MacOS' }
    elseif ($IsLinux) { 'Linux' }
    else { 'Unknown' }
}

function Get-YesWorkflowExe {

	[cmdletbinding()]
	Param(
        [ValidateSet('Windows','MacOS','Linux')] [string] $os,
        [ValidateSet('x86','x64')]               [string] $platform = 'x64',
        [ValidateSet('Debug','Release')]         [string] $build    = 'Release',
                                                 [string] $repoRoot = '../..',
                                                 [string] $exe      = $null
	)

    if (!$exe) {
        if ($os -eq "Windows") {
            if ($platform -eq 'x64') {
                $exe = "${repoRoot}/msvc/x64/${build}/yw-graph-app.exe"
            } else {
                $exe = "${repoRoot}/msvc/${build}/yw-graph-app.exe"
            }
        } else {
            $exe = "${repoRoot}/gcc/yw-graph-app/yw-graph-app"
        }
    }

    try {
        return Get-Item $exe -ErrorAction Stop | Select-Object -ExpandProperty FullName
    } Catch {
        throw "YW executable not found at '$exe'"
    }
}

function Out-FileDiff {

	[cmdletbinding()]
	Param(
        [int]$line,
		[string]$expected,
		[string]$actual
	)
    
    "Difference found at line ${line}:"
    "Actual   : $actual"
    "Expected : $expected"
}

function Find-FirstDiff {

	[cmdletbinding()]
	Param(
		[string]$expected,
		[string]$actual
	)
	
	Process {
    
        $actualContent = Get-Content $actual
		$expectedContent = Get-Content $expected
    
        $commonLength = [System.Math]::Min($actualContent.Length, $expectedContent.Length)
		for ($i = 0; $i -lt $commonLength; ++$i) {
			if ($actualContent[$i] -ne $expectedContent[$i]) {
				return Out-FileDiff ($i + 1) $actualContent[$i] $expectedContent[$i]
			}
		}

		if ($actualContent.Length -ne $expectedContent.Length) {
            if ($actualContent.Length -gt $expectedContent.Length) {
                return Out-FileDiff ($commonLength + 1) "<End of file>" $actualContent[$i]
            } else {
                return Out-FileDiff ($commonLength + 1)  $expectedContent[$i] "<End of file>"
            }
		}
	}
}
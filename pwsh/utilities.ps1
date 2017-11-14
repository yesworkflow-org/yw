

function Get-YesWorkflowPlatform {
    if ($IsWindows) { 'Windows' } 
    elseif ($IsMacOS) { 'MacOS' }
    elseif ($IsLinux) { 'Linux' }
    else { 'Unknown' }
}

function Get-YesWorkflowPath {

	[cmdletbinding()]
	Param(
        [string]$os,
		[string]$platform='x64',
        [string]$build='Release',
        [string]$repoRoot='../..'
	)

    if ($os -eq "Windows") {
        if ($platform -eq 'x64') {
            "${repoRoot}/msvc/x64/${build}/yw-graph-app.exe"
        } else {
            "${repoRoot}/msvc/${build}/yw-graph-app.exe"
        }
    } else {
        "${repoRoot}/gcc/yw-graph-app/yw-graph-app"
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
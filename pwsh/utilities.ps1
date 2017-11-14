

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
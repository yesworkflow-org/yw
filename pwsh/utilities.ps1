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
				"Difference found at line $($i + 1):"
				"Actual   : $($actualContent[$i])"
				"Expected : $($expectedContent[$i])"
				return
			}
		}

		if ($actualContent.Length -gt $expectedContent.Length) {
			"Difference found at line $($commonLength + 1)"
			"Actual   : $($actualContent[$i])"
			"Expected : <End of file>"
			return
		}

		if ($actualContent.Length -lt $expectedContent.Length) {
			"Difference found at line $($commonLength + 1)"
			"Actual   : <End of file>"
			"Expected : $($expectedContent[$i])"
			return
		}
	}
}
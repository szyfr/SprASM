Clear-Host

$tag = "cx16"
$exe = "/SPRASM.PRG"
$src = "src/main.asm"
$cpy = 'LOAD"TARGET/DEBUG/'


$date = [string](Get-Date).year + "-" + [string](Get-Date).month + "-" + [string](Get-Date).day
$executableLocation = "target/debug/" + $date

if ((Test-Path $executableLocation) -eq $FALSE) {
	$temp = "./" + $executableLocation
	"...Creating a new directory..."
	New-Item $temp -ItemType "directory" | Out-Null
}

Copy-Item -Path ".\src" -Destination ".\$executableLocation" -Force -Recurse


$stopwatch =  [system.diagnostics.stopwatch]::StartNew()
&"cl65" "-t"$tag $src "-o"$executableLocation$exe
$stopwatch.Stop()


if ($LASTEXITCODE -eq 0) {
	$space = " "
	$milliseconds = [math]::Round($stopwatch.Elapsed.TotalMilliSeconds,0)
	$milliLength = $milliseconds.ToString().length
	$sizeBytes = (Get-Item $executableLocation$exe).length
	$sizeLength = $sizeBytes.ToString().length

	$temp = 10 - $milliLength
	$temp = $space * $temp
	$temp2 = 10 - $sizeLength
	$temp2 = $space * $temp2

	"... Assembly Successful ..."
	"...Time:"+ $temp + $milliseconds + " milis..."
	"...Size:"+ $temp2 + $sizeBytes + " bytes..."

	Set-Clipboard $cpy$date$exe
	&"x16emu" "-scale" "2" "-quality" "nearest"
}
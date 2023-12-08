# File paths
Rename-Item -Path "$env:USERPROFILE\Documents\Shoushiling\main.exe" -NewName "Shoushiling 手勢令.exe"
$sourceFile = "$env:USERPROFILE\Documents\Shoushiling\Shoushiling 手勢令.exe"
$destinationFolder = "$env:USERPROFILE\Desktop"
$shortcutName = "Shoushiling 手勢令.lnk"
$iconPath = "$env:USERPROFILE\Documents\Shoushiling\assets\images\icons\scissors.ico"
$startIn = "$env:USERPROFILE\Documents\Shoushiling"

# Create a WScript Shell object
$shell = New-Object -ComObject WScript.Shell

# Create a shortcut
$shortcut = $shell.CreateShortcut("$destinationFolder\$shortcutName")
$shortcut.TargetPath = $sourceFile
$shortcut.IconLocation = $iconPath
$shortcut.WorkingDirectory = $startIn # Set the Start in field
$shortcut.Save()

# Rename the shortcut
Rename-Item -Path "$env:USERPROFILE\Desktop\Shoushiling 手勢令.lnk" -NewName "Shoushiling 手勢令.lnk"

@echo off
color fc

goto check_Permissions

:check_Permissions
echo Administrative permissions required. Detecting permissions...
cls
net session >nul 2>&1
if %errorLevel% == 0 (
    echo Success: Administrative permissions confirmed.
) else (
    echo Failure: Administrative permissions required.
    pause >nul
    goto check_Permissions
)

title ZOMBIU XPatcher pdm[Patcher]
echo Example: C:\Program Files (x86)\Steam\steamapps\common\ZOMBI
echo Example: D:\steamapps\common\ZOMBI
SET /P M=Type Enter Your ZOMBIU Install Directory: 
netsh advfirewall firewall add rule name="ZOMBI_XPatcher" dir=out program="%M%\ZOMBI_Game.exe" profile=any action=block
netsh advfirewall firewall add rule name="ZOMBI_XPatcher" dir=in program="%M%\ZOMBI_Game.exe" profile=any action=block

netsh advfirewall firewall add rule name="ZOMBI_XPatcher" dir=out program="%M%\ZOMBI.exe" profile=any action=block
netsh advfirewall firewall add rule name="ZOMBI_XPatcher" dir=in program="%M%\ZOMBI.exe" profile=any action=block
echo Patching ZOMBI.exe = OK
pause
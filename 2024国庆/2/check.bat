echo off
:flag
maker.exe
good.exe
me.exe
fc good.out bad.out
if not errorlevel 1 goto flag
pause
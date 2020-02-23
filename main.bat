@echo off
set var=
setlocal enabledelayedexpansion
FOR /R "src/" %%g IN (*.c) DO ( 
   (Echo "%%g" | FIND /I "driver.c" 1>NUL) || (
        set var=!var!  %%g
   )
)
cls && echo Compiling main... && gcc -Wall !var! -o bin/main && echo Compilation done! && pause && cls && bin\main
endlocal
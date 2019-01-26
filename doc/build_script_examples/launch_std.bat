@echo off

set APP_NAME=teststd
set APP_NAME_PAL=%APP_NAME%_pal
set APP_NAME_NTSC=%APP_NAME%_ntsc
set APP_NAME_SECAM=%APP_NAME%_secam
set BUILD_DIR=binout


"C:\Program Files\Stella\Stella.exe" -bs 4K %BUILD_DIR%\%APP_NAME_PAL%.4k


REM "C:\Program Files\Stella\Stella.exe" -bs 4K %BUILD_DIR%\%APP_NAME_NTSC%.4k


REM "C:\Program Files\Stella\Stella.exe" -bs 4K %BUILD_DIR%\%APP_NAME_SECAM%.4k

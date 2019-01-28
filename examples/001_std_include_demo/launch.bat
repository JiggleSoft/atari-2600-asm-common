@echo off
rem Launch Script Using Simple DOS Batch File Only.

set APP_NAME=std_include_demo
set BIN_DIR=binout
set EMUL="C:\Program Files\Stella\Stella.exe"

set APP_NAME_PAL=%APP_NAME%_pal
set APP_NAME_NTSC=%APP_NAME%_ntsc
set APP_NAME_SECAM=%APP_NAME%_secam


@echo on


%EMUL% -bs 4K -format PAL %BUILD_DIR%\%APP_NAME_PAL%.4k


%EMUL% -bs 4K -format NTSC %BUILD_DIR%\%APP_NAME_NTSC%.4k


%EMUL% -bs 4K -format SECAM %BUILD_DIR%\%APP_NAME_SECAM%.4k


@echo off

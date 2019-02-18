@echo off
rem Clean Script Using Simple DOS Batch File Only.

set APP_NAME=stdx_rtim_demo
set BUILD_DIR=binout
set BIN_DIR=binout

set APP_NAME_PAL=%APP_NAME%_pal
set APP_NAME_NTSC=%APP_NAME%_ntsc
set APP_NAME_SECAM=%APP_NAME%_secam


del %BUILD_DIR%\%APP_NAME_PAL%.o
del %BUILD_DIR%\%APP_NAME_PAL%.map
del %BUILD_DIR%\%APP_NAME_PAL%.lst
del %BUILD_DIR%\%APP_NAME_PAL%.labels
del %BIN_DIR%\%APP_NAME_PAL%.4k


del %BUILD_DIR%\%APP_NAME_NTSC%.o
del %BUILD_DIR%\%APP_NAME_NTSC%.map
del %BUILD_DIR%\%APP_NAME_NTSC%.lst
del %BUILD_DIR%\%APP_NAME_NTSC%.labels
del %BIN_DIR%\%APP_NAME_NTSC%.4k


del %BUILD_DIR%\%APP_NAME_SECAM%.o
del %BUILD_DIR%\%APP_NAME_SECAM%.map
del %BUILD_DIR%\%APP_NAME_SECAM%.lst
del %BUILD_DIR%\%APP_NAME_SECAM%.labels
del %BIN_DIR%\%APP_NAME_SECAM%.4k

@ECHO OFF
REM Build Script Using Simple DOS Batch File Only.

set APP_NAME=std_include_demo
set BUILD_DIR=binout
set BIN_DIR=binout


set CC65_HOME=c:\opt\cc65
set CC65_BIN_DIR=%CC65_HOME%\bin
set CC65_INC_DIR=%CC65_HOME%\asminc


set APP_NAME_PAL=%APP_NAME%_pal
set APP_NAME_NTSC=%APP_NAME%_ntsc
set APP_NAME_SECAM=%APP_NAME%_secam


set STD_CFG_DIR=..\..\src\std\asmcfg
set STD_INC_DIR=..\..\src\std\asminc


set APP_SRC_DIR=.\src\asm
set APP_INC_DIR=.\src\asminc


mkdir %BUILD_DIR% >NUL: 2>&1
mkdir %BIN_DIR% >NUL: 2>&1


C:\opt\cc65\bin\ca65.exe -D PLATFORM_PAL=1 -I %CC65_INC_DIR% -I %STD_INC_DIR% -I %APP_INC_DIR% --cpu 6502 -t atari2600 -l %BUILD_DIR%\%APP_NAME_PAL%.lst %APP_SRC_DIR%\%APP_NAME%.asm -o %BUILD_DIR%\%APP_NAME_PAL%.o
C:\opt\cc65\bin\ld65.exe -C %STD_CFG_DIR%\a2k6_4k.cfg -m %BUILD_DIR%\%APP_NAME_PAL%.map -Ln %BUILD_DIR%\%APP_NAME_PAL%.labels -vm %BUILD_DIR%\%APP_NAME_PAL%.o -o %BIN_DIR%\%APP_NAME_PAL%.4k


C:\opt\cc65\bin\ca65.exe -D PLATFORM_NTSC=1 -I %CC65_INC_DIR% -I %STD_INC_DIR% -I %APP_INC_DIR% --cpu 6502 -t atari2600 -l %BUILD_DIR%\%APP_NAME_NTSC%.lst %APP_SRC_DIR%\%APP_NAME%.asm -o %BUILD_DIR%\%APP_NAME_NTSC%.o
C:\opt\cc65\bin\ld65.exe -C %STD_CFG_DIR%\a2k6_4k.cfg -m %BUILD_DIR%\%APP_NAME_NTSC%.map -Ln %BUILD_DIR%\%APP_NAME_NTSC%.labels -vm %BUILD_DIR%\%APP_NAME_NTSC%.o -o %BIN_DIR%\%APP_NAME_NTSC%.4k


C:\opt\cc65\bin\ca65.exe -D PLATFORM_SECAM=1 -I %CC65_INC_DIR% -I %STD_INC_DIR% -I %APP_INC_DIR% --cpu 6502 -t atari2600 -l %BUILD_DIR%\%APP_NAME_SECAM%.lst %APP_SRC_DIR%\%APP_NAME%.asm -o %BUILD_DIR%\%APP_NAME_SECAM%.o
C:\opt\cc65\bin\ld65.exe -C %STD_CFG_DIR%\a2k6_4k.cfg -m %BUILD_DIR%\%APP_NAME_SECAM%.map -Ln %BUILD_DIR%\%APP_NAME_SECAM%.labels -vm %BUILD_DIR%\%APP_NAME_SECAM%.o -o %BIN_DIR%\%APP_NAME_SECAM%.4k

@echo off

set APP_NAME=testkpf0
set APP_NAME_PAL=%APP_NAME%_pal
set APP_NAME_NTSC=%APP_NAME%_ntsc
set APP_NAME_SECAM=%APP_NAME%_secam
set BUILD_DIR=binout


set STD_CFG_DIR=..\..\src\std\asmcfg
set STD_INC_DIR=..\..\src\std\asminc
set STDX_INC_DIR=..\..\src\stdx\asminc
set STDX_INC_TODO_DIR=..\..\src\stdx\asminc_todo
set KERNEL_INC_DIR=..\..\src\kernel\asminc


set SRC_DIR=..\..\src\test\kernel\asm
set INC_DIR=..\..\src\test\kernel\asminc


set CC65_HOME=c:\opt\cc65
set CC65_BIN_DIR=%CC65_HOME%\bin

rem set PATH=%PATH%:C:\opt\cc65\bin


mkdir %BUILD_DIR% >NUL: 2>&1


C:\opt\cc65\bin\ca65.exe -D PLATFORM_PAL=1 -I %CC65_HOME%\asminc -I %STD_INC_DIR% -I %STDX_INC_DIR% -I %STDX_INC_TODO_DIR%  -I %KERNEL_INC_DIR% -I %INC_DIR% --cpu 6502 -t atari2600 -l %BUILD_DIR%\%APP_NAME_PAL%.lst %SRC_DIR%\%APP_NAME%.asm -o %BUILD_DIR%\%APP_NAME_PAL%.o
C:\opt\cc65\bin\ld65.exe -C %STD_CFG_DIR%\a2k6_4k.cfg -m %BUILD_DIR%\%APP_NAME_PAL%.map -Ln %BUILD_DIR%\%APP_NAME_PAL%.labels -vm %BUILD_DIR%\%APP_NAME_PAL%.o -o %BUILD_DIR%\%APP_NAME_PAL%.4k


C:\opt\cc65\bin\ca65.exe -D PLATFORM_NTSC=1 -I %CC65_HOME%\asminc -I %STD_INC_DIR% -I %STDX_INC_DIR% -I %STDX_INC_TODO_DIR% -I %KERNEL_INC_DIR% -I %INC_DIR% --cpu 6502 -t atari2600 -l %BUILD_DIR%\%APP_NAME_NTSC%.lst %SRC_DIR%\%APP_NAME%.asm -o %BUILD_DIR%\%APP_NAME_NTSC%.o
C:\opt\cc65\bin\ld65.exe -C %STD_CFG_DIR%\a2k6_4k.cfg -m %BUILD_DIR%\%APP_NAME_NTSC%.map -Ln %BUILD_DIR%\%APP_NAME_NTSC%.labels -vm %BUILD_DIR%\%APP_NAME_NTSC%.o -o %BUILD_DIR%\%APP_NAME_NTSC%.4k


C:\opt\cc65\bin\ca65.exe -D PLATFORM_SECAM=1 -I %CC65_HOME%\asminc -I %STD_INC_DIR% -I %STDX_INC_DIR% -I %STDX_INC_TODO_DIR% -I %KERNEL_INC_DIR% -I %INC_DIR% --cpu 6502 -t atari2600 -l %BUILD_DIR%\%APP_NAME_SECAM%.lst %SRC_DIR%\%APP_NAME%.asm -o %BUILD_DIR%\%APP_NAME_SECAM%.o
C:\opt\cc65\bin\ld65.exe -C %STD_CFG_DIR%\a2k6_4k.cfg -m %BUILD_DIR%\%APP_NAME_SECAM%.map -Ln %BUILD_DIR%\%APP_NAME_SECAM%.labels -vm %BUILD_DIR%\%APP_NAME_SECAM%.o -o %BUILD_DIR%\%APP_NAME_SECAM%.4k

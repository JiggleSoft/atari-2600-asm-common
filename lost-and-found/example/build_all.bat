@echo off
rem Run All Build Scripts Using Simple DOS Batch File Only.


cd 001_std_include_demo
call build.bat
cd ..


cd 002_stdx_rtim_demo
call build.bat
cd ..

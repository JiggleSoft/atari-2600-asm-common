@echo off

cd std
build_std.bat
cd ..

cd stdx
build_stdx.bat
cd ..

cd kernel
build_kernel.bat
cd ..

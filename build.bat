@echo off
title build PrintLength
cd /d %~dp0

for /f "delims=" %%i in ('dir /b *.pyd') do (
    del %%i
)

python build.py build_ext --inplace

for /f "delims=" %%i in ('dir /b *.pyd') do (
    for /f "tokens=1 delims=." %%a in ("%%i") do (
        ren %%i %%a.pyd
    )
)

if exist build (
    rmdir /s /q build
)

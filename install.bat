@echo off
title install PrintLength
cd /d %~dp0

python setup.py install
rd /s /q dist
rd /s /q build
rd /s /q PrintLength.egg-info

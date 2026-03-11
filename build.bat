


@echo off

if not exist ..\build mkdir ..\build

pushd ..\build

cl ..\code\win32_platform.c

popd



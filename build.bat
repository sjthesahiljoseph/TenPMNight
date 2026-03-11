


@echo off

if not exist build mkdir build

pushd build

cl ..\win32_platform.c user32.lib

popd



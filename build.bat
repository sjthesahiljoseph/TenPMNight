


@echo off

if not exist build mkdir build

pushd build

cl ..\win32_platform.c

popd



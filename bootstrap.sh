#!/bin/sh

# TODO: use script dir, not .

# clear old cmake generated fiels
find . -name CMakeCache.txt -o -name CMakeFiles -o -name Makefile -o -name cmake_install.cmake | xargs rm -rf

# generate Makefiles, etc.
cmake . -DCMAKE_MODULE_PATH=/usr/lib/OGRE/cmake

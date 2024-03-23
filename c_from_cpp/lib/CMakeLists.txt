project(mylib)

set(mylib_VERSION_MAJOR 0)
set(mylib_VERSION_MINOR 0)
set(mylib_VERSION_TEENY 1)
set(PACKAGE_VERSION "${mylib_VERSION_MAJOR}.${mylib_VERSION_MINOR}.${mylib_VERSION_TEENY}")

cmake_minimum_required(VERSION 3.5)

set(LIB_SRC src/sample.c)

add_library(mylib SHARED ${LIB_SRC})

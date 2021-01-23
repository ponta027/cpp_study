project(stream_sample)

set(1_VERSION_MAJOR 0)
set(1_VERSION_MINOR 0)
set(1_VERSION_TEENY 1)
set(PACKAGE_VERSION "${1_VERSION_MAJOR}.${1_VERSION_MINOR}.${1_VERSION_TEENY}")

cmake_minimum_required(VERSION 3.5)

add_executable( stream_sample src/stream_sample.cpp)




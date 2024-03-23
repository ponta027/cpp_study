project(sample)

set(SAMPLE_VERSION_MAJOR 0)
set(SAMPLE_VERSION_MINOR 0)
set(SAMPLE_VERSION_TEENY 1)
set(PACKAGE_VERSION "${SAMPLE_VERSION_MAJOR}.${SAMPLE_VERSION_MINOR}.${SAMPLE_VERSION_TEENY}")

cmake_minimum_required(VERSION 2.8)

add_executable( sample  src/main.cpp)

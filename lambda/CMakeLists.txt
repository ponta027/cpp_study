project(lambda_sample)

set(1_VERSION_MAJOR 0)
set(1_VERSION_MINOR 0)
set(1_VERSION_TEENY 1)
set(PACKAGE_VERSION "${1_VERSION_MAJOR}.${1_VERSION_MINOR}.${1_VERSION_TEENY}")

cmake_minimum_required(VERSION 3.5)


add_executable( lambda_sample src/lambda_sample.cpp)
add_executable( lambda_codezine src/lambda_codezine.cpp)



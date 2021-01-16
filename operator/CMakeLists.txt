cmake_minimum_required( VERSION 3.5)
project(operator CXX)
set(CMAKE_CXX_FLAGS "-O2 -std=c++11")
add_executable( operator src/operator.cpp)

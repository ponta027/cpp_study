cmake_minimum_required( VERSION 3.5 )
project( c_from_cpp CXX)
add_subdirectory(lib)
add_executable( c_from_cpp
    src/main.cpp
)
target_include_directories(c_from_cpp PUBLIC inc/)
target_link_libraries( c_from_cpp PRIVATE mylib)



cmake_minimum_required(VERSION 3.10)

project(design_pattern  CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(design_pattern src/main.cpp )
target_include_directories(design_pattern 
  PRIVATE 
  ${CMAKE_SOURCE_DIR}/libs/singleton/inc
)

target_link_libraries(design_pattern 
  singleton
)

add_subdirectory(libs)
add_subdirectory(tests)


add_custom_target(
   test
   ctest --test-dir tests --output-junit report.xml
)

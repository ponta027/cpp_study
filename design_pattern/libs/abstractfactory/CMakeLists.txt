
set( LIBRARY_NAME abstractfactory)
project(${LIBRARY_NAME} CXX)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


file(GLOB SRC_FILES "src/*.cpp")
add_library(
  ${LIBRARY_NAME}
  SHARED
  ${SRC_FILES}
)
target_include_directories(
  ${LIBRARY_NAME}
  PRIVATE 
  ${CMAKE_SOURCE_DIR}/inc/
)


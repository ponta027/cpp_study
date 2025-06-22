set(EXECUTABLE_NAME "test_design_pattern")
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)
enable_testing()

set(GTEST_INCLUDE_DIR ${gtest_SOURCE_DIR}/include)
set(GMOCK_INCLUDE_DIR ${gmock_SOURCE_DIR}/include)
include_directories(${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR})


file(GLOB SRC_FILES "src/*.cpp")
add_executable(
  ${EXECUTABLE_NAME}
  ${SRC_FILES}
)
target_link_libraries(
  ${EXECUTABLE_NAME}
  GTest::gtest_main
  GTest::gmock
  singleton
  factory
  abstractfactory
  builder
  template
)
target_include_directories(
  ${EXECUTABLE_NAME}
  PRIVATE 
  ${CMAKE_SOURCE_DIR}/libs/abstractfactory/inc
  ${CMAKE_SOURCE_DIR}/libs/builder/inc
  ${CMAKE_SOURCE_DIR}/libs/factory/inc
  ${CMAKE_SOURCE_DIR}/libs/singleton/inc
  ${CMAKE_SOURCE_DIR}/libs/template/inc
)

include(GoogleTest)

gtest_discover_tests(${EXECUTABLE_NAME})



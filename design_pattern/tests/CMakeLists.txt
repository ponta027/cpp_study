set(EXECUTABLE_NAME "hello_test")
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()


file(GLOB SRC_FILES "src/*.cpp")
add_executable(
  ${EXECUTABLE_NAME}
  ${SRC_FILES}
)
target_link_libraries(
  ${EXECUTABLE_NAME}
  GTest::gtest_main
  singleton
  factory
  abstractfactory
)
target_include_directories(
  ${EXECUTABLE_NAME}
  PRIVATE 
  ${CMAKE_SOURCE_DIR}/libs/singleton/inc
  ${CMAKE_SOURCE_DIR}/libs/factory/inc
  ${CMAKE_SOURCE_DIR}/libs/abstractfactory/inc
)

include(GoogleTest)

gtest_discover_tests(${EXECUTABLE_NAME})



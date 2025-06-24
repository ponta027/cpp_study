set( LIBRARY_NAME adapter)
file(GLOB SRC_FILES "src/*.cpp")


add_library(
  ${LIBRARY_NAME}
  SHARED
  ${SRC_FILES}
)

target_include_directories(
    ${LIBRARY_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/libs/adapter/inc
)

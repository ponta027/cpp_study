set(LIBRARY builder)

file(GLOB SRC_FILES "src/*.cpp")
add_library( ${LIBRARY} 
  SHARED
  ${SRC_FILES}
)

target_include_directories(${LIBRARY}
  PRIVATE 
  ${CMAKE_SOURCE_DIR}/inc
  ${CMAKE_SOURCE_DIR}/libs/builder/inc
)



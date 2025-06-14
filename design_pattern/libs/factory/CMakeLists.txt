
set(LIBRARY_NAME factory)
file(GLOB SRC_FILES "src/*.cpp")
add_library( ${LIBRARY_NAME}
  SHARED
  ${SRC_FILES}
)

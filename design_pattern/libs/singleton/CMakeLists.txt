
set(LIBRARY_NAME singleton)
file(GLOB SRC_FILES "src/*.cpp")
add_library( ${LIBRARY_NAME}
  SHARED
  ${SRC_FILES}
)

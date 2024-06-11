set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -DNDEBUG -O2 -s")

# Output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib)

# Intermediate files (object files)
set(CMAKE_BINARY_DIR_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_BINARY_DIR_RELEASE ${CMAKE_BINARY_DIR}/Release)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# enable detection of memory leaks in Linux
if(UNIX)
  set(CMAKE_CXX_FLAGS_DEBUG
      "${CMAKE_CXX_FLAGS_DEBUG}
    -fno-omit-frame-pointer
    -fsanitize=address
    -g")
  set(CMAKE_LINKER_FLAGS_DEBUG
      "${CMAKE_LINKER_FLAGS_DEBUG}
    -fno-omit-frame-pointer
    -fsanitize=address
    -g
    ")
endif()

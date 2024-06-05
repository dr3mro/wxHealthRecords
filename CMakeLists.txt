cmake_minimum_required(VERSION 3.29 FATAL_ERROR)
set(Target "Health_Records")
project(${Target} LANGUAGES CXX)

set(Depends "${CMAKE_CURRENT_SOURCE_DIR}/Depends/")
set(Bundle "${CMAKE_CURRENT_SOURCE_DIR}/Bundle/")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Sources/*.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2 -s")

add_subdirectory("${Depends}")

if(APPLE)
  add_executable(${Target} MACOSX_BUNDLE ${SOURCES})
  set_target_properties(${Target} PROPERTIES MACOSX_BUNDLE_INFO_PLIST
                                             ${Bundle}/Info.plist)
else()
  add_executable(${Target} WIN32 ${SOURCES} ${Bundle}Application.rc)
endif()

target_link_libraries(${Target} PRIVATE wxcore wxnet)

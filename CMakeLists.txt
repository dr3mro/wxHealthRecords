cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
set(Target "Health_Records")
project(${Target} LANGUAGES C CXX)

set(Bundle "${CMAKE_CURRENT_SOURCE_DIR}/Bundle/")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Sources/*.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -DNDEBUG -O2 -s")
set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -g")
set(CMAKE_LINKER_FLAGS_DEBUG
    "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -g")

# download CPM.cmake
file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH
    SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

if(UNIX)
  add_executable(${Target} ${SOURCES})
  find_package(wxWidgets REQUIRED COMPONENTS net core base)

  if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include("${wxWidgets_USE_FILE}")
  endif()

  target_link_libraries(${Target} PRIVATE ${wxWidgets_LIBRARIES})

elseif(APPLE)
  add_executable(${Target} MACOSX_BUNDLE ${SOURCES})
  find_package(wxWidgets REQUIRED COMPONENTS net core base)

  if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include("${wxWidgets_USE_FILE}")
  endif()

  set_target_properties(${Target} PROPERTIES MACOSX_BUNDLE_INFO_PLIST
                                             ${Bundle}/Info.plist)
  target_link_libraries(${Target} PRIVATE core net base)
elseif(WIN32)

  set(wxWidgets_USE_STATIC 1)
  set(wxBUILD_SHARED OFF)
  set(wxUSE_STL ON)

  cpmaddpackage(
    NAME
    wxWidgets
    URL
    https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.5/wxWidgets-3.2.5.7z
    VERSION
    3.2.5
    HASH
    "SHA1=8d25f17f7c5064fa39271b8dc0fd06ca24d760c1")
  add_executable(${Target} WIN32 ${SOURCES} ${Bundle}Application.rc)
  target_link_libraries(${Target} PRIVATE wxcore wxnet)
endif()

# Add a custom target to strip symbols from the executable
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_custom_target(
    strip ALL
    COMMAND ${CMAKE_STRIP} $<TARGET_FILE:${Target}>
    DEPENDS $<TARGET_FILE:${Target}>)
endif()

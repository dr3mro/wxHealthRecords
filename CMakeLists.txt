cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
set(Target "Health_Records")
project(${Target} LANGUAGES CXX)

set(Depends "${CMAKE_CURRENT_SOURCE_DIR}/Depends/")
set(Bundle "${CMAKE_CURRENT_SOURCE_DIR}/Bundle/")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Sources/*.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2 -s")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

add_subdirectory("${Depends}")

if(UNIX)
  add_executable(${Target} ${SOURCES} )
  find_package(wxWidgets REQUIRED COMPONENTS net core base)
  if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include("${wxWidgets_USE_FILE}")
  endif()
  target_link_libraries(${Target} PRIVATE ${wxWidgets_LIBRARIES})
elseif(APPLE)
  add_executable(${Target} MACOSX_BUNDLE ${SOURCES})
  set_target_properties(${Target} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${Bundle}/Info.plist)
  target_link_libraries(${Target} PRIVATE core net)
else()
  if(MSVC)
    add_executable(${Target} WIN32 ${SOURCES} ${Bundle}Application.rc)
  else()
    add_executable(${Target} WIN32 ${SOURCES} ${Bundle}Application.manifest)
  endif()
  target_link_libraries(${Target} PRIVATE wxcore wxnet)

endif()


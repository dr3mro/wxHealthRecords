cpmaddpackage(
  NAME
  wxWidgets
  URL
  https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.5/wxWidgets-3.2.5.7z
  VERSION
  3.2.5
  HASH
  "SHA1=8d25f17f7c5064fa39271b8dc0fd06ca24d760c1"
  OPTIONS
  "wxUSE_STATIC_RUNTIME ON"
  "wxBUILD_SHARED OFF"
  "wxBUILD_STATIC ON"
  "wxUSE_STL ON")

add_executable(${Target} WIN32 ${SOURCES} ${Bundle}Application.rc)

target_include_directories(${Target}
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Sources/")
target_link_libraries(${Target} PRIVATE wxcore wxnet wxbase wxaui)
# ##############################################################################
# Add a custom target to strip symbols from the executable
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_custom_target(
    strip ALL
    COMMAND ${CMAKE_STRIP} $<TARGET_FILE:${Target}>
    DEPENDS $<TARGET_FILE:${Target}>)
endif()

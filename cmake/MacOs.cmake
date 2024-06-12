# Add wxWidgets as a dependency
CPMAddPackage(
  NAME
  wxWidgets
  URL
  https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.5/wxWidgets-3.2.5.tar.bz2
  VERSION 3.2.5
  HASH    "SHA1=da39a3ee5e6b4b0d3255bfef95601890afd80709"
  OPTIONS "wxBUILD_SHARED OFF" "wxUSE_STL ON"
)

# Add the source files for your project
add_executable(${Target} MACOSX_BUNDLE ${SOURCES})

# Link wxWidgets to your project
target_link_libraries(${Target} PRIVATE wx::net wx::core wx::base)

# Include wxWidgets headers
target_include_directories(${Target} PRIVATE ${wxWidgets_SOURCE_DIR}/include)

set_target_properties(${Target} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${Bundle}/Info.plist)

target_include_directories(${Target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Sources/")
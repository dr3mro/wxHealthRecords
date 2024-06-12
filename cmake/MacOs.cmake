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



# Set the icon file path
set(MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Bundle/icon.icns)
# Set the wns wave file path
set(MACOSX_BUNDLE_WNS_WAV_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Bundle/wns.wav)
# Set the Font Awesome file path
set(MACOSX_BUNDLE_FA_FONT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Bundle/fa-regular-400.ttf)

# Specify the icon file as a resource
set_source_files_properties(${MACOSX_BUNDLE_ICON_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

# Specify the wav file as a resource
set_source_files_properties(${MACOSX_BUNDLE_WNS_WAV_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

# Specify the Font Awesome file as a resource
set_source_files_properties(${MACOSX_BUNDLE_FA_FONT_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources/Fonts")

# Add the source files for your project
add_executable(${Target} MACOSX_BUNDLE ${MACOSX_BUNDLE_ICON_FILE} ${MACOSX_BUNDLE_WNS_WAV_FILE} ${MACOSX_BUNDLE_FA_FONT_FILE} ${SOURCES})

# Link wxWidgets to your project
target_link_libraries(${Target} PRIVATE wx::net wx::core wx::base)

# Include wxWidgets headers
target_include_directories(${Target} PRIVATE ${wxWidgets_SOURCE_DIR}/include)

set_target_properties(${Target} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${Bundle}/Info.plist)

target_include_directories(${Target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Sources/")




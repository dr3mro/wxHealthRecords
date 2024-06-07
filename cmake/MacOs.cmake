add_executable(${Target} MACOSX_BUNDLE ${SOURCES})
find_package(wxWidgets REQUIRED COMPONENTS net core base aui)

if(wxWidgets_USE_FILE) # not defined in CONFIG mode
  include("${wxWidgets_USE_FILE}")
endif()

set_target_properties(${Target} PROPERTIES MACOSX_BUNDLE_INFO_PLIST
                                           ${Bundle}/Info.plist)
target_link_libraries(${Target} PRIVATE core net base aui)

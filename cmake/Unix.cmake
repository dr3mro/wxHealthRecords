# Add wxWidgets as a dependency
CPMAddPackage(
  NAME
  wxWidgets
  URL
  https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.5/wxWidgets-3.2.5.tar.bz2
  VERSION 3.2.5
  HASH    "SHA1=da39a3ee5e6b4b0d3255bfef95601890afd80709"
  OPTIONS "wxBUILD_SHARED OFF" "wxUSE_STL OFF" "wxUSE_PRIVATE_FONTS ON"
)



#find_package(wxWidgets REQUIRED COMPONENTS net core base aui)
# Add the source files for your project
add_executable(${Target} ${SOURCES})
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
  include("${wxWidgets_USE_FILE}")
endif()
# Include wxWidgets headers
target_include_directories(${Target} PRIVATE ${wxWidgets_INCLUDE_DIRS})

target_include_directories(${Target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Sources/")

target_link_libraries(${Target} PRIVATE wx::net wx::core wx::base)


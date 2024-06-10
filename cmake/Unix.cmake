add_executable(${Target} ${SOURCES})
find_package(wxWidgets REQUIRED COMPONENTS net core base aui)

if(wxWidgets_USE_FILE) # not defined in CONFIG mode
  include("${wxWidgets_USE_FILE}")
endif()
target_include_directories(${Target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Sources/")
target_link_libraries(${Target} PRIVATE ${wxWidgets_LIBRARIES})

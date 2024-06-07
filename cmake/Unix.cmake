add_executable(${Target} ${SOURCES})
find_package(wxWidgets REQUIRED COMPONENTS net core base aui)

if(wxWidgets_USE_FILE) # not defined in CONFIG mode
  include("${wxWidgets_USE_FILE}")
endif()

target_link_libraries(${Target} PRIVATE ${wxWidgets_LIBRARIES})

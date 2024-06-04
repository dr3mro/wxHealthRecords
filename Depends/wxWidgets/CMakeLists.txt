IF (WIN32)
include(FetchContent)
set(wxBUILD_SHARED OFF)
set(wxUSE_STL ON)
message(STATUS "Fetching wxWidgets...")
FetchContent_Declare(
  wxWidgets
  URL  https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.5/wxWidgets-3.2.5.7z
  URL_HASH  SHA1=8d25f17f7c5064fa39271b8dc0fd06ca24d760c1
  USES_TERMINAL_DOWNLOAD TRUE
)
FetchContent_MakeAvailable(wxWidgets)
ELSE()
message(STATUS "Make sure wxWidgets is installed...")
ENDIF()

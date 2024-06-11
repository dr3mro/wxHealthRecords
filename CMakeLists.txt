cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
set(Target "Health_Records")
project(${Target} LANGUAGES C CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(Vars)

include(Flags)

include(AutoCCache)

include(CPM)

if(UNIX)
  include(Unix)
elseif(APPLE)
  include(MacOs)
elseif(WIN32)
  include(Windows)
endif()

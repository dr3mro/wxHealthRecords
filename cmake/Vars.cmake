set(Bundle "${CMAKE_CURRENT_SOURCE_DIR}/Bundle/")

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Sources/*")

if(APPLE)
  list(REMOVE_ITEM SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/Sources/SoundEffects/SoundEffectsImpl.cpp")
  list(REMOVE_ITEM SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/Sources/SoundEffects/SoundEffectsImpl.hpp")
else()
  list(
    REMOVE_ITEM SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Sources/SoundEffects/SoundEffectsImplApple.cpp"
  )
  list(
    REMOVE_ITEM SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Sources/SoundEffects/SoundEffectsImplApple.hpp"
  )
  list(REMOVE_ITEM SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/Sources/Common/CommonApple.hpp")
endif()

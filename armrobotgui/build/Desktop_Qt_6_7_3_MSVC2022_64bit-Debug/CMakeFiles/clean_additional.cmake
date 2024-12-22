# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\armrobotgui_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\armrobotgui_autogen.dir\\ParseCache.txt"
  "armrobotgui_autogen"
  )
endif()

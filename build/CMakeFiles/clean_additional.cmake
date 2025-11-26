# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/EduConnect_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/EduConnect_autogen.dir/ParseCache.txt"
  "EduConnect_autogen"
  )
endif()

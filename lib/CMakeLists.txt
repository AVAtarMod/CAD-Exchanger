cmake_minimum_required(VERSION 3.14)
project(curves3d-cxx)

# Always include the source and build directories in the include path.

# create the static library
add_library(${PROJECT_NAME} SHARED base.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)

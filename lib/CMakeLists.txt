cmake_minimum_required(VERSION 3.14)
project(curves3d-cxx)

# create the core library
add_library(${PROJECT_NAME}-core SHARED core.cpp)
set_target_properties(
  ${PROJECT_NAME}-core
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)
target_link_options(
  ${PROJECT_NAME}-core PRIVATE
  "LINKER:--version-script=${CMAKE_CURRENT_SOURCE_DIR}/core.ld")

# create the static library
add_library(${PROJECT_NAME} STATIC base.cpp objects.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} INTERFACE ${PROJECT_NAME}-core)
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)

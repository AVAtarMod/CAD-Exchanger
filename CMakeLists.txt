cmake_minimum_required(VERSION 3.14)
project(CAD_Exchanger_PWT CXX)

set(CMAKE_CXX_STANDARD 17)
# Always include the source and build directories in the include path.
set(CMAKE_INCLUDE_CURRENT_DIR OFF)

find_package(OpenMP REQUIRED)


# create the executable
add_executable(main main.cpp ${data})

add_subdirectory(lib)
target_include_directories(main PRIVATE lib)
target_link_libraries(main PRIVATE curves3d-cxx)
target_link_libraries(main PUBLIC OpenMP::OpenMP_CXX)

cmake_minimum_required(VERSION 3.10)

# set the project name
project(Apple)

SET(GCC_COVERAGE_LINK_FLAGS "-pthread")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# add the executable
add_executable(Apple.out gateway.cpp)
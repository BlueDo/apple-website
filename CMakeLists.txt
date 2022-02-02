cmake_minimum_required(VERSION 3.10)

# set the project name
project(Apple)

SET(GCC_COVERAGE_LINK_FLAGS "-pthread")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")


find_path(CROW_INCLUDE_DIRS "crow.h")

# add the executable
add_executable(Apple.out src/gateway.cpp)

target_include_directories(Apple.out PRIVATE ${CROW_INCLUDE_DIRS})

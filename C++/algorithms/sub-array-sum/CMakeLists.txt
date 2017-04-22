cmake_minimum_required(VERSION 3.7)

project(sub-array-sump)

set(EXEC_NAME sub-array-sum)

set(SOURCE_FILES sub-array-sum.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXECUTABLE_OUTPUT_PATH ../../dist/${CMAKE_BUILD_TYPE})

add_executable(${EXEC_NAME} ${SOURCE_FILES})

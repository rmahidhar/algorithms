cmake_minimum_required(VERSION 3.7)

project(interval)

set(EXEC_NAME interval)

set(SOURCE_FILES interval.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXECUTABLE_OUTPUT_PATH ../../dist/${CMAKE_BUILD_TYPE})

add_executable(${EXEC_NAME} ${SOURCE_FILES})

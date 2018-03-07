cmake_minimum_required(VERSION 3.7)

project(atmost-k-unique-chars)

set(EXEC_NAME atmost-k-unique-chars)

set(SOURCE_FILES atmost-k-unique-chars.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXECUTABLE_OUTPUT_PATH ../../dist/${CMAKE_BUILD_TYPE})

add_executable(${EXEC_NAME} ${SOURCE_FILES})

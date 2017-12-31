cmake_minimum_required(VERSION 3.7)

project(word-search)

set(EXEC_NAME word-search)

set(SOURCE_FILES word-search.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXECUTABLE_OUTPUT_PATH ../../dist/${CMAKE_BUILD_TYPE})

add_executable(${EXEC_NAME} ${SOURCE_FILES})

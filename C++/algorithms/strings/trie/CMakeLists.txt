cmake_minimum_required(VERSION 3.7)

project(trie)

set(EXEC_NAME trie)

set(SOURCE_FILES trie.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXECUTABLE_OUTPUT_PATH ../../dist/${CMAKE_BUILD_TYPE})

add_executable(${EXEC_NAME} ${SOURCE_FILES})

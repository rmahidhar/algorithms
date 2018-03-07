cmake_minimum_required(VERSION 3.7)

project(countandsay)

set(EXEC_NAME countandsay)

set(SOURCE_FILES countandsay.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXECUTABLE_OUTPUT_PATH ../../dist/${CMAKE_BUILD_TYPE})

add_executable(${EXEC_NAME} ${SOURCE_FILES})

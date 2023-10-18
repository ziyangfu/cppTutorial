cmake_minimum_required(VERSION 3.26)
project(ClassModelTest)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS ${PROJECT_SOURCE_DIR}/*.hpp)

add_executable(ClassModelTest main.cpp ${SRCS})

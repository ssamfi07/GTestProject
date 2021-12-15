cmake_minimum_required (VERSION 3.7)

project(UTProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(UTProject
                src/main.cpp
                src/Account.cpp
                )

include_directories(
                src/
)

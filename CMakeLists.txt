cmake_minimum_required (VERSION 3.7)

project(tema)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(tema
                src/Account.cpp
                )

include_directories(
                src/
)

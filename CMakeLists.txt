cmake_minimum_required (VERSION 3.7)

project(UTProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(UTProject
                src/main.cpp
                src/Account/Account.cpp
                src/Employee/Employee.cpp
                src/logger/Logger.cpp
                )

include_directories(
                src/
                src/Account
                src/utils
                src/logger
                src/Employee
)

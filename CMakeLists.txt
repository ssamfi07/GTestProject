cmake_minimum_required (VERSION 3.7)

project(UTProject)

# add definitions
add_definitions(-lboost_log -DBOOST_ALL_DYN_LINK -lpthread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lboost_log -DBOOST_ALL_DYN_LINK -lpthread")

find_package(Boost COMPONENTS program_options log log_setup REQUIRED)
set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})

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
                src/handlers
)


target_link_libraries(UTProject pthread)
target_link_libraries(UTProject ${PROJECT_LIB})

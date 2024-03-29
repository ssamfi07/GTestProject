cmake_minimum_required (VERSION 3.7)
project(UTProjectTest)

# add definitions
add_definitions(-lgtest -lm -fprofile-arcs -ftest-coverage -lpthread -lboost_log -DBOOST_ALL_DYN_LINK)

# Include diretories
include_directories(/usr/include)
link_directories(/usr/local/lib)

# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -O0 -Wall -lgtest -fprofile-arcs -ftest-coverage -lboost_log -DBOOST_ALL_DYN_LINK -lpthread -lm")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/UTProjectTest.dir/src)
message("-- Object files will be output to: ${OBJECT_DIR}")

# Find required packages for gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(Boost COMPONENTS program_options log log_setup REQUIRED)
set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})


# Set the sources
set(sources
                src/test_main.cpp
                src/AccountTest.cpp
                # src/EmployeesHandlerTest.cpp
                src/EmployeeTest.cpp
                src/UseEmployeesTest.cpp
                ../src/Account/Account.cpp
                ../src/Employee/Employee.cpp
                ../src/logger/Logger.cpp
                )
# Set Include directories
include_directories(
                src/
                input/
                mocks/
                ../src/Account
                ../src/Employee
                ../src/utils
                ../src/logger
                ../src/handlers
                )

# Create the executable
add_executable(UTProjectTest ${sources})

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p gcoverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Source directory: ${CMAKE_SOURCE_DIR}/src/"
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
    )
add_dependencies(gcov UTProjectTest)

# Create the lcov target. Run result tests with 'make lcov'
add_custom_target(lcov
    COMMAND mkdir -p lcoverage
    )
add_custom_command(TARGET lcov
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov -rc lcov_branch_coverage=1 --capture --directory ../ --output-file lcoverage/temp.info
    # command to remove the non-wanted sources
    COMMAND lcov --rc lcov_branch_coverage=1 --remove lcoverage/temp.info "/usr/local/include/gtest/*" "/usr/local/include/gmock/*" "/usr/local/include/gtest/internal/*" "/usr/local/include/gmock/internal/*" "*/usr/include/*" "*test/src/*" --output-file lcoverage/coverage.info
    COMMAND echo "-- Generating HTML output files"
    COMMAND genhtml --rc genhtml_branch_coverage=1 lcoverage/coverage.info --output-directory lcoverage
    )

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES gcoverage)

# Create the gcov-clean target. This cleans the build as well as generated 
# .gcda and .gcno files.
add_custom_target(init
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

# Testing
enable_testing()

add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/UTProjectTest)

# link Boost libraries to the new target

target_link_libraries(UTProjectTest ${PROJECT_LIB})
target_link_libraries(UTProjectTest gtest)
target_link_libraries(UTProjectTest gmock)
target_link_libraries(UTProjectTest pthread)
target_link_libraries(UTProjectTest -fprofile-arcs)
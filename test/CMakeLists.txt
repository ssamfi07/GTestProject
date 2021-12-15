cmake_minimum_required (VERSION 3.7)
project(TestTema)

# add definitions
add_definitions(-fprofile-arcs -ftest-coverage)

# Include diretories
include_directories(/usr/include)
link_directories(/usr/lib)

# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/TestTema.dir/src)
message("-- Object files will be output to: ${OBJECT_DIR}")

# Find required packages
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Set the sources
set(sources
                src/AccountTest.cpp
                ../src/Account.cpp
                )
# Set Include directories
include_directories(
                src/
                ../src/
                )

# Create the executable
add_executable(TestTema ${sources})

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
add_dependencies(gcov TestTema)

# Create the lcov target. Run result tests with 'make lcov'
add_custom_target(lcov
    COMMAND mkdir -p lcoverage
    )
add_custom_command(TARGET lcov
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov -rc lcov_branch_coverage=1 --capture --directory ../ --output-file lcoverage/temp.info
    # command to remove the non-wanted sources
    COMMAND lcov --rc lcov_branch_coverage=1 --remove lcoverage/temp.info "/usr/local/include/gtest/*" "/usr/local/include/gtest/internal/*" "*/usr/include/*" "*test/src/*" --output-file lcoverage/coverage.info
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
# enable_testing()

# add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/TestTema)

# link Boost libraries to the new target
target_link_libraries(TestTema gtest)
target_link_libraries(TestTema gmock)
target_link_libraries(TestTema pthread)
target_link_libraries(TestTema -fprofile-arcs)
# target_link_libraries(TestTema gcov)
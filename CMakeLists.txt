cmake_minimum_required(VERSION 3.2)
project(cpp_project_template)
set(PROJECT_NAME "cpp_project_template")
####################################################################################################
####################################################################################################

# Build flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_C_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -Wall -Wextra -Werror -Wsign-conversion -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -Wall -Wextra -Werror -Wsign-conversion -pedantic")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -Wall -Wextra -Werror -Wsign-conversion -pedantic")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -Wall -Wextra -Werror -Wsign-conversion -pedantic")

# Output vars
set(LIB_TARGET ${PROJECT_NAME})
set(TEST_LIB "catch")
set(TEST_TARGET "${PROJECT_NAME}_tests")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Input vars
set(SRC_DIR "src")
set(INC_DIR "inc")
set(TEST_DIR "test")

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.c)
add_library(${LIB_TARGET} STATIC ${SOURCES})

# The Catch testing library
add_library(${TEST_LIB} INTERFACE)
target_include_directories(${TEST_LIB} INTERFACE ${TEST_DIR}/${INC_DIR})

# The test binary
include_directories(${INC_DIR})
file(GLOB_RECURSE TEST_SOURCES ${TEST_DIR}/*.cpp ${TEST_DIR}/*.c)
add_executable(${TEST_TARGET} ${TEST_SOURCES})
target_link_libraries(${TEST_TARGET} ${TEST_LIB})
target_link_libraries(${TEST_TARGET} ${LIB_TARGET})

# Expose tests to CMake
enable_testing()
add_test(NAME ${TEST_TARGET} COMMAND ${TEST_TARGET})

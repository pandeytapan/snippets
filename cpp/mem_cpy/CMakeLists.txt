cmake_minimum_required(VERSION 3.20.0)

# set the variables to be used further
set(PROJECT_NAME mem.cpy.test)
set(PROJECT_NUMBER 1.0.0)

##############################
# Set additional compiler option
##############################
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

##############################
# Project name
##############################
project(${PROJECT_NAME} VERSION 1.0 DESCRIPTION "memory block copy verifier" LANGUAGES CXX)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

# guard against bad build-type strings
if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "Default build is Debug")
  set(CMAKE_BUILD_TYPE "DEBUG")
endif()

# Display build status
message("Building ${PROJECT_NAME} version ${PROJECT_VERSION}")
message("cmake source directory: ${CMAKE_SOURCE_DIR}")
message("cmake current build directory: ${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(${PROJECT_NAME} mem_cpy_assert.cpp)
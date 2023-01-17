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
project(${PROJECT_NAME} VERSION 1.0 DESCRIPTION "memcopy" LANGUAGES CXX)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

# guard against bad build-type strings
if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "Default build is Debug")
  set(CMAKE_BUILD_TYPE "DEBUG")
endif()

add_subdirectory(./mem_cpy)
add_subdirectory(./include)

target_link_libraries("${PROJECT_NAME}.assert" PUBLIC cpp-test-headers-macro-comp)
target_link_libraries("${PROJECT_NAME}.test" PUBLIC cpp-test-headers-macro-comp GTest::gtest_main)
  

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )

# include(GoogleTest)
# gtest_discover_tests("${PROJECT_NAME}.test")
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


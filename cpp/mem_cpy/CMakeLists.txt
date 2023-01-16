# Display build status
message("Building ${PROJECT_NAME} version ${PROJECT_VERSION}")
message("cmake source directory: ${CMAKE_SOURCE_DIR}")
message("cmake current build directory: ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable("${PROJECT_NAME}.assert" mem_cpy_assert.cpp)
add_executable("${PROJECT_NAME}.test" mem_cpy_test.cpp)
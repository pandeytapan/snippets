# Display build status
message("Building ${PROJECT_NAME} version ${PROJECT_VERSION}")
message("cmake source directory: ${CMAKE_SOURCE_DIR}")
message("cmake current build directory: ${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(${PROJECT_NAME} mem_cpy_assert.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC cpp-test-headers-macro-comp)
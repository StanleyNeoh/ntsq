cmake_minimum_required(VERSION 3.10)

project(ntsq VERSION 1.0)

add_subdirectory(utils)
add_subdirectory(network_tree)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC network_tree utils)
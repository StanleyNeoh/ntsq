cmake_minimum_required(VERSION 3.10)

project(ntsq VERSION 1.0)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)

add_subdirectory(utils)
add_subdirectory(network_tree)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC compiler_flags
    PUBLIC network_tree 
    PUBLIC utils
)

add_executable(test_${PROJECT_NAME} test.cpp)
target_link_libraries(
    test_${PROJECT_NAME} 
    PUBLIC compiler_flags
    PUBLIC test_network_tree
    PUBLIC test_utils
)

install(
    TARGETS ${PROJECT_NAME} 
    DESTINATION bin
    PERMISSIONS WORLD_EXECUTE
)
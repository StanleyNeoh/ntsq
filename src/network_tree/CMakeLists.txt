add_library(network_tree network_tree.cpp)
target_include_directories(network_tree INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(test_network_tree test/test_network_tree.cpp)
target_include_directories(test_network_tree INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/test)
target_link_libraries(test_network_tree PRIVATE network_tree)

add_library(utils utils.cpp)
target_include_directories(utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(test_utils test/test_utils.cpp)
target_include_directories(test_utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/test)
target_link_libraries(test_utils PRIVATE utils)

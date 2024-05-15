#include "test_utils.hpp"
#include "test_network_tree.hpp"

#include <iostream>

int main() {
    bool success = true;
    success &= test_utils_convert_subnet_to_bin();
    success &= test_utils_convert_bin_to_subnet();
    success &= test_network_tree_insert_and_retrieve();
    success &= test_network_tree_squish();
    if (success) {
        std::clog << "=== All Test Passed ===\n";
    } else {
        std::clog << "=== Some Test Failed ===\n";
    }
}
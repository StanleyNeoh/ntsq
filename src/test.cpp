#include "test_utils.hpp"

#include <iostream>

int main() {
    bool success = true;
    success &= test_utils_convert_subnet_to_bin();
    success &= test_utils_convert_bin_to_subnet();
    if (success) {
        std::clog << "=== All Test Passed ===\n";
    } else {
        std::clog << "=== Some Test Failed ===\n";
    }
}
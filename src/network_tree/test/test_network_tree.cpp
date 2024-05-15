#include "test_network_tree.hpp"
#include "network_tree.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

bool test_network_tree_insert_and_retrieve()
{
    std::clog << "=== Testing 'network_tree' insert and retrieve ===\n";
    bool success = true;
    const std::unordered_set<std::string> original{
        "110000001010100000000001",
        "1100000010101000000",
        "0000101000000000",
        "0000101000000000111",
        "1010110000010000000001010000",
        "110010110000000001110001",
        "110000001010100001100100001",
        "00001010000010100000000",
        "10101100000101000000010010",
        "110010110000000001110001010000",
        "11000000101010000011001000000",
        "0000101011111111000010100",
        "",
        "11111111111111111111111111111111",
        "1111111111111111111111",
    };
    network_tree ntwk = network_tree();
    for (auto iter = original.begin(); iter != original.end(); iter++)
    {
        ntwk.add_network(*iter);
    }

    std::vector<std::string> dumped;
    ntwk.dump(dumped);
    if (dumped.size() != original.size())
    {
        std::clog << "DIFFERENT SIZES - FAIL\n";
        success = false;
    }
    else
    {
        std::clog << "SAME SIZES - OK\n";
    }

    std::unordered_set<std::string> result(dumped.begin(), dumped.end());
    for (auto iter = original.begin(); iter != original.end(); iter++)
    {
        if (result.find(*iter) == result.end())
        {
            std::clog << "CAN'T FIND " << *iter << " IN RESULT - FAIL\n";
            success = false;
        }
        else
        {
            std::clog << "FOUND " << *iter << " IN RESULT - OK\n";
        }
    }
    for (auto iter = result.begin(); iter != result.end(); iter++)
    {
        if (original.find(*iter) == original.end())
        {
            std::clog << "FOUND EXTRA " << *iter << " NOT IN ORIGINAL - FAIL\n";
            success = false;
        }
        else
        {
            std::clog << "FOUND " << *iter << " IN ORIGINAL - OK\n";
        }
    }
    return success;
}
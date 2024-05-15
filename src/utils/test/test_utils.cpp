#include "test_utils.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>
#include <vector>

bool test_utils_convert_subnet_to_bin()
{
    std::clog << "=== Testing 'utils' convert_subnet_to_bin ===\n";
    bool success = true;
    const std::vector<std::string> valid_subnets{
        "192.168.1.0/24",
        "10.0.0.0/16",
        "172.16.5.0/28",
        "203.0.113.0/24",
        "192.168.100.32/27",
        "10.10.0.0/23",
        "172.20.4.128/26",
        "203.0.113.64/30",
        "192.168.50.0/29",
        "10.255.10.0/25",
        "0.0.0.0/0",
        "255.255.255.255/32",
    };
    const std::vector<std::string> valid_subnets_bin{
        "110000001010100000000001",
        "0000101000000000",
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
    };
    for (int i = 0; i < valid_subnets.size(); i++)
    {
        const std::string &subnet = valid_subnets[i];
        const std::string &expected = valid_subnets_bin[i];
        std::string result;
        if (!convert_subnet_to_bin(subnet, result))
        {
            std::clog << "FAILED TO CONVERT: " << subnet << " - FAIL\n";
            success = false;
            continue;
        }
        if (expected != result)
        {
            std::clog << "DOES NOT MATCH: " << subnet << ", EXPECTED: " << expected << ", GOT: " << result << " - FAIL\n";
            success = false;
            continue;
        }
        std::clog << "MATCH: " << subnet << ", GOT: " << result << " - OK\n";
    }
    return success;
}

bool test_utils_convert_bin_to_subnet()
{
    std::clog << "=== Testing 'utils' convert_bin_to_subnet ===\n";
    bool success = true;
    const std::vector<std::string> valid_subnets_bin{
        "110000001010100000000001",
        "0000101000000000",
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
    };
    const std::vector<std::string> valid_subnets{
        "192.168.1.0/24",
        "10.0.0.0/16",
        "172.16.5.0/28",
        "203.0.113.0/24",
        "192.168.100.32/27",
        "10.10.0.0/23",
        "172.20.4.128/26",
        "203.0.113.64/30",
        "192.168.50.0/29",
        "10.255.10.0/25",
        "0.0.0.0/0",
        "255.255.255.255/32",
    };
    for (int i = 0; i < valid_subnets.size(); i++)
    {
        const std::string &bin = valid_subnets_bin[i];
        const std::string &expected = valid_subnets[i];
        std::string result = convert_bin_to_subnet(bin);
        if (expected != result)
        {
            std::clog << "DOES NOT MATCH: " << bin << ", EXPECTED: " << expected << ", GOT: " << result << " - FAIL\n";
            success = false;
            continue;
        }
        std::clog << "MATCH: " << bin << ", GOT: " << result << " - OK\n";
    }
    return success;
}

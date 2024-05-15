#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <string>
#include <vector>

bool is_valid_ip(const std::string &ip_address, std::vector<u_int8_t> &segments);
bool is_valid_subnet(const std::string &subnet, std::vector<u_int8_t> &segments, size_t &netsize);
std::string to_byte_str(u_int8_t num);
u_int8_t from_byte_str(const std::string &binstr);
bool convert_subnet_to_bin(const std::string &subnet, std::string &binstr);
std::string convert_bin_to_subnet(const std::string &binary);
#endif
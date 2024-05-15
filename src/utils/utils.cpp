#include <sstream>
#include <string>
#include <vector>
#include <iostream>

bool is_valid_ip(const std::string &ip_address, std::vector<u_int8_t> &segments)
{
    std::stringstream ss(ip_address);
    std::string seg;
    int seg_count = 0;
    int temp;
    while (getline(ss, seg, '.'))
    {
        if (++seg_count > 4)
            return false;
        std::stringstream sseg(seg);
        if (!(sseg >> temp) || temp < 0 || temp > 255)
            return false;
        segments.push_back(temp);
        if (!(sseg.eof()))
            return false;
    }
    return seg_count == 4;
}

bool is_valid_subnet(const std::string &subnet, std::vector<u_int8_t> &segments, size_t &netsize)
{
    size_t ind = subnet.find('/');
    std::string ip = subnet.substr(0, ind);
    if (!is_valid_ip(ip, segments))
        return false;

    std::stringstream ss(subnet.substr(ind + 1));
    if (!(ss >> netsize) || netsize < 0 || netsize > 32)
        return false;
    return ss.eof();
}

std::string to_byte_str(u_int8_t num)
{
    std::string s;
    for (int i = 7; i >= 0; i--)
    {
        s += (num & (1 << i)) ? '1' : '0';
    }
    return s;
}

u_int8_t from_byte_str(const std::string &binstr)
{
    u_int8_t ret = 0;
    for (int i = 0; i < binstr.size(); i++) {
        ret <<= 1;
        ret |= (binstr[i] != '0');
    }
    return ret;
}

bool convert_subnet_to_bin(const std::string &subnet, std::string &binstr)
{
    std::vector<u_int8_t> segs;
    size_t netsize;
    if (!is_valid_subnet(subnet, segs, netsize))
        return false;
    std::stringstream ss;
    for (int i = 0; i < segs.size(); i++)
    {
        ss << to_byte_str(segs[i]);
    }
    binstr = ss.str().substr(0, netsize);
    return true;
}

std::string convert_bin_to_subnet(const std::string &binary)
{
    size_t netsize = binary.size();
    const std::string full_binary = binary + std::string(32-netsize, '0');
    std::string seg_1 = std::to_string(from_byte_str(full_binary.substr(0, 8)));
    std::string seg_2 = std::to_string(from_byte_str(full_binary.substr(8, 8)));
    std::string seg_3 = std::to_string(from_byte_str(full_binary.substr(16, 8)));
    std::string seg_4 = std::to_string(from_byte_str(full_binary.substr(24, 8)));
    std::string size = std::to_string(netsize);
    return seg_1 + '.' + seg_2 + '.' + seg_3 + '.' + seg_4 + '/' + size;
}

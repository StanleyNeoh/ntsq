#include "network_tree.hpp"
#include "utils.hpp"

#include <vector>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    network_tree ntwk_tree;
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line == "end")
            break;
        std::string binstr;
        if (!convert_subnet_to_bin(line, binstr))
        {
            std::clog << "Unable to convert " << line << '\n';
            continue;
        }
        ntwk_tree.add_network(std::move(binstr), 0);
    }
    ntwk_tree.squish();
    std::vector<std::string> result;
    ntwk_tree.dump(result);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << convert_bin_to_subnet(result[i]) << '\n';
    }
    return 0;
}
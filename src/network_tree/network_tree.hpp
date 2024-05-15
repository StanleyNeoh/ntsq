#ifndef NETWORK_TREE_H
#define NETWORK_TREE_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class network_tree
{
private:
    char value;
    std::unique_ptr<network_tree> next_0;
    std::unique_ptr<network_tree> next_1;

    void dump_reversed(std::vector<std::string> &result)
    {
        if (next_0 == nullptr && next_1 == nullptr)
        {
            result.push_back(std::string(1, value));
            return;
        }

        std::vector<std::string> temp;
        if (next_0 != nullptr)
            next_0->dump_reversed(temp);
        if (next_1 != nullptr)
            next_1->dump_reversed(temp);
        int len = temp.size();
        for (int i = 0; i < len; i++)
        {
            if (value != '?')
                temp[i] += value;
            result.push_back(temp[i]);
        }
    }

public:
    network_tree() : value('?') {}
    network_tree(char value) : value(value) {}

    void add_network(const std::string &subnet, int ind)
    {
        if (ind >= subnet.size())
        {
            return;
        }
        if (subnet[ind] == '0')
        {
            if (next_0 == nullptr)
            {
                next_0 = std::make_unique<network_tree>('0');
            }
            next_0->add_network(subnet, ind + 1);
        }
        else
        {
            if (next_1 == nullptr)
            {
                next_1 = std::make_unique<network_tree>('1');
            }
            next_1->add_network(subnet, ind + 1);
        }
    }

    void dump(std::vector<std::string> &result)
    {
        std::vector<std::string> temp;
        dump_reversed(temp);
        int len = temp.size();
        for (int i = 0; i < len; i++)
        {
            std::reverse(temp[i].begin(), temp[i].end());
        }
        result.insert(result.begin(), temp.begin(), temp.end());
    }
};

#endif
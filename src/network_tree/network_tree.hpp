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
    static const char sentinel = '?';
    bool present;
    char value;
    std::unique_ptr<network_tree> next_0;
    std::unique_ptr<network_tree> next_1;

    void dump_reversed(std::vector<std::string> &result) const
    {
        std::vector<std::string> temp;
        if (present)
            temp.push_back("");
        if (next_0 != nullptr)
            next_0->dump_reversed(temp);
        if (next_1 != nullptr)
            next_1->dump_reversed(temp);
        int len = temp.size();
        for (int i = 0; i < len; i++)
        {
            if (value != sentinel)
                temp[i] += value;
            result.push_back(temp[i]);
        }
    }

public:
    network_tree() : value(sentinel), present(false) {}
    network_tree(char value) : value(value), present(false) {}

    void add_network(const std::string &subnet, int ind)
    {
        if (ind >= subnet.size())
        {
            present = true;
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
    void add_network(const std::string &subnet)
    {
        add_network(subnet, 0);
    }

    void dump(std::vector<std::string> &result) const
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
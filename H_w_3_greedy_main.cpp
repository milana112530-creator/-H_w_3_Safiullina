#include <iostream>
#include "H_w_3_greedy.h"

int main()
{
    std::string filename = "ks_19_0";

    std::vector<ItemG> items;
    int capacity;

    if (!readDataGreedy(filename, items, capacity)){
        std::cout << "Error reading file\n";
        return 1;
    }

    int result = greedyKnapsack(items, capacity);

    std::cout << "Greedy result (value/weight): " << result << std::endl;

    return 0;
}
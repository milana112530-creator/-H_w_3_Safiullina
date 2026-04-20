#include "H_w_3_greedy.h"
#include <fstream>
#include <algorithm>

bool readDataGreedy(const std::string& filename, std::vector<ItemG>& items, int& capacity)
{
    std::ifstream file(filename);
    if (!file) return false;

    int n;
    file >> n >> capacity;

    items.resize(n);

    for (int i = 0; i < n; i++){
        file >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    return true;
}

int greedyKnapsack(const std::vector<ItemG>& items, int capacity){
    std::vector<ItemG> sorted = items;

    std::sort(sorted.begin(), sorted.end(), [](ItemG a, ItemG b){
        return a.ratio > b.ratio;
    });

    int totalValue = 0;
    int totalWeight = 0;

    for (const auto& item : sorted){
        if (totalWeight + item.weight <= capacity){
            totalWeight += item.weight;
            totalValue += item.value;
        }
    }

    return totalValue;
}
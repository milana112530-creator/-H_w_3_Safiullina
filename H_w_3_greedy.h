#include <vector>
#include <string>

struct ItemG {
    int value;
    int weight;
    double ratio;
};

bool readDataGreedy(const std::string& filename, std::vector<ItemG>& items, int& capacity);

int greedyKnapsack(const std::vector<ItemG>& items, int capacity);

#ifndef GREEDYKNAPSACK_H
#define GREEDYKNAPSACK_H

#include <vector>
#include "Item.h"

class GreedyKnapsack {
public:
    std::pair<int, size_t> solve(int capacity, std::vector<Item>& items);
};

#endif //GREEDYKNAPSACK_H

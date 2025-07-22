#ifndef DYNAMICPROGRAMMINGKNAPSACK_H
#define DYNAMICPROGRAMMINGKNAPSACK_H

#include <vector>
#include "Item.h"

class DynamicProgrammingKnapsack {
public:
    std::pair<int, size_t> solve(int capacity, const std::vector<Item>& items);
};

#endif //DYNAMICPROGRAMMINGKNAPSACK_H

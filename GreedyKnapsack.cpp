#include "GreedyKnapsack.h"
#include <algorithm>
#include <vector>

std::pair<int, size_t> GreedyKnapsack::solve(int capacity, std::vector<Item>& items) {
    size_t memory_usage = items.size() * sizeof(Item);
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    });

    int totalValue = 0;
    int currentWeight = 0;

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        }
    }

    return {totalValue, memory_usage};
}

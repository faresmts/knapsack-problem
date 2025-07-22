#include "DynamicProgrammingKnapsack.h"
#include <vector>
#include <algorithm>

std::pair<int, size_t> DynamicProgrammingKnapsack::solve(int capacity, const std::vector<Item>& items) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));
    size_t memory_usage = (n + 1) * (capacity + 1) * sizeof(int);

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = std::max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return {dp[n][capacity], memory_usage};
}

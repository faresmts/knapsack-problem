#include "Benchmark.h"

int main() {
    Benchmark benchmark;

    int num_runs = 100000;
    int num_items = 5000;
    int capacity = 10000;
    int max_value = 1000;
    int max_weight = 500;
    std::string filename = "knapsack_results_10.csv";

    benchmark.run(num_items, capacity, num_runs, filename, max_weight, max_value);
    return 0;
}

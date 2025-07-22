#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>
#include "Item.h"

class Benchmark {
public:
    void run(int num_items, int capacity, int num_runs, const std::string& filename, int max_weight, int max_value);

private:
    std::vector<Item> generate_items(int num_items, int max_weight, int max_value);
};

#endif //BENCHMARK_H

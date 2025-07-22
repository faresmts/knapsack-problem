#include "Benchmark.h"
#include "DynamicProgrammingKnapsack.h"
#include "GreedyKnapsack.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

std::vector<Item> Benchmark::generate_items(int num_items, int max_weight, int max_value) {
    std::vector<Item> items(num_items);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weight_dist(1, max_weight);
    std::uniform_int_distribution<> value_dist(1, max_value);

    for (int i = 0; i < num_items; ++i) {
        items[i] = {weight_dist(gen), value_dist(gen)};
    }
    return items;
}

void Benchmark::run(int num_items, int capacity, int num_runs, const std::string& filename, int max_weight, int max_value) {
    std::ofstream results_file(filename);
    if (!results_file.is_open()) {
        std::cerr << "Error opening results file." << std::endl;
        return;
    }

    results_file << "DP execution time (ns),Heuristic execution time (ns),DP solution,Heuristic solution,DP memory usage (bytes),Heuristic memory usage (bytes),Solutions are the same\n";

    DynamicProgrammingKnapsack dp_solver;
    GreedyKnapsack greedy_solver;

    for (int i = 0; i < num_runs; ++i) {
        std::vector<Item> items = generate_items(num_items, max_weight, max_value);
        std::vector<Item> items_for_greedy = items;

        auto start_dp = std::chrono::high_resolution_clock::now();
        auto dp_result = dp_solver.solve(capacity, items);
        auto end_dp = std::chrono::high_resolution_clock::now();
        auto duration_dp = std::chrono::duration_cast<std::chrono::nanoseconds>(end_dp - start_dp).count();

        auto start_greedy = std::chrono::high_resolution_clock::now();
        auto greedy_result = greedy_solver.solve(capacity, items_for_greedy);
        auto end_greedy = std::chrono::high_resolution_clock::now();
        auto duration_greedy = std::chrono::duration_cast<std::chrono::nanoseconds>(end_greedy - start_greedy).count();

        int dp_solution = dp_result.first;
        size_t dp_memory = dp_result.second;
        int greedy_solution = greedy_result.first;
        size_t greedy_memory = greedy_result.second;

        bool same_solution = (dp_solution == greedy_solution);

        results_file << duration_dp << "," << duration_greedy << "," << dp_solution << "," << greedy_solution << "," << dp_memory << "," << greedy_memory << "," << (same_solution ? "Yes" : "No") << "\n";
    }

    results_file.close();
    std::cout << "Benchmark finished. Results saved to " << filename << std::endl;
}

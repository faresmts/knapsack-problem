cmake_minimum_required(VERSION 3.10)
project(KnapsackProblem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(knapsack_problem main.cpp DynamicProgrammingKnapsack.cpp GreedyKnapsack.cpp Benchmark.cpp)

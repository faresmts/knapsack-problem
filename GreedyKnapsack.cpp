#include "GreedyKnapsack.h"
#include <algorithm>
#include <vector>

/**
 * @brief Resolve o Problema da Mochila usando uma abordagem gulosa (heurística).
 * 
 * Esta função ordena os itens em ordem decrescente pela sua razão valor/peso.
 * Em seguida, itera sobre os itens ordenados, adicionando-os à mochila se eles
 * couberem, até que a capacidade seja atingida. Esta abordagem é rápida mas não
 * garante a solução ótima.
 * 
 * @param capacity A capacidade máxima da mochila.
 * @param items O vetor de itens disponíveis. Este vetor será ordenado internamente.
 * @return std::pair<int, size_t> Um par contendo o valor total da solução encontrada e
 * o uso de memória estimado.
 */
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

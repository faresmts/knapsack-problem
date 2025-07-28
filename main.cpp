/**
 * @file main.cpp
 * @brief Ponto de entrada principal para a execução do benchmark do Problema da Mochila.
 * 
 * Este arquivo inicializa e executa o benchmark que compara as abordagens de
 * programação dinâmica e gulosa para o Problema da Mochila,
 * gerando os resultados em um arquivo CSV.
 */
#include "Benchmark.h"

/**
 * @brief Função principal que configura e executa o benchmark.
 * @return int Retorna 0 após a conclusão bem-sucedida.
 */
int main() {
    // Cria uma instância da classe de benchmark.
    Benchmark benchmark;

    // Define os parâmetros para a execução do benchmark.
    int num_runs = 100000;   // Número de vezes que o cenário será executado.
    int num_items = 5000;    // Número de itens a serem gerados para cada execução.
    int capacity = 10000;    // Capacidade da mochila.
    int max_value = 1000;    // Valor máximo para um item gerado aleatoriamente.
    int max_weight = 500;    // Peso máximo para um item gerado aleatoriamente.

    // Define o nome do arquivo de saída para os resultados do benchmark.
    std::string filename = "knapsack_results_10.csv";

    // Executa o benchmark com os parâmetros definidos.
    benchmark.run(num_items, capacity, num_runs, filename, max_weight, max_value);

    return 0;
}

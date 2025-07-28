import pandas as pd
import glob
import os

def generate_comparative_table():
    path = r'/home/fares/projects/knapsack-problem'
    csv_files = sorted(glob.glob(os.path.join(path, "knapsack_results_*.csv")))

    results = []

    for f in csv_files:
        df = pd.read_csv(f)

        scenario_number = os.path.basename(f).split('_')[-1].split('.')[0]

        num_executions = len(df)

        if num_executions == 0:
            continue

        avg_time_dp = df['DP execution time (ns)'].mean()
        avg_time_heuristic = df['Heuristic execution time (ns)'].mean()

        avg_mem_dp = df['DP memory usage (bytes)'].mean()
        avg_mem_heuristic = df['Heuristic memory usage (bytes)'].mean()

        hit_rate = (df['Solutions are the same'].str.strip().str.lower() == 'yes').sum() / num_executions
        hit_rate = hit_rate * 100

        results.append({
            'Número do Cenário': scenario_number,
            'Quantidade de execuções': num_executions,
            'Média do Tempo de Execução (DP)': round(avg_time_dp, 2),
            'Média do Tempo de Execução (Gulosa)': round(avg_time_heuristic, 2),
            'Média do uso de memória (DP)': round(avg_mem_dp, 2),
            'Média do uso de memória (Gulosa)': round(avg_mem_heuristic, 2),
            'Taxa de acerto': round(hit_rate, 2)
        })

    if not results:
        print("No data to process.")
        return

    final_df = pd.DataFrame(results)
    output_path = os.path.join(path, 'comparative_results.csv')
    final_df.to_csv(output_path, index=False)
    print(f"Tabela comparativa salva em: {output_path}")

if __name__ == '__main__':
    generate_comparative_table()

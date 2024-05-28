import pandas as pd
from matplotlib import pyplot as plt

def mst_matrix(data):
    densities = [25, 50, 75, 99]

    for key, value in data:
        for density in densities:
            filtered_data = value[value['density'] == density]
            x = filtered_data['vertices']
            y = filtered_data['time']
            plt.plot(x, y, label = key.removesuffix('-matrix-Wyniki.csv') + ' ' + str(density) + '%', marker='.')

    plt.xlabel('vertices')
    plt.ylabel('time [us]')
    plt.title('MST matrix')
    plt.legend()
    plt.savefig('plots/MST-matrix.png', bbox_inches='tight')
    plt.close()

def mst_list(data):
    densities = [25, 50, 75, 99]

    for key, value in data:
        for density in densities:
            filtered_data = value[value['density'] == density]
            x = filtered_data['vertices']
            y = filtered_data['time']
            plt.plot(x, y, label = key.removesuffix('-list-Wyniki.csv') + ' ' + str(density) + '%', marker='.')

    plt.xlabel('vertices')
    plt.ylabel('time [us]')
    plt.title('MST list')
    plt.legend()
    plt.savefig('plots/MST-list.png', bbox_inches='tight')
    plt.close()

def mst_density(data):
    densities = [25, 50, 75, 99]

    for density in densities:
        for key, value in data:
            filtered_data = value[value['density'] == density]
            x = filtered_data['vertices']
            y = filtered_data['time']
            plt.plot(x, y, label = key.removesuffix('-Wyniki.csv'), marker='.')
        plt.xlabel('vertices')
        plt.ylabel('time [us]')
        plt.title(f'MST density: {density}%')
        plt.legend()
        plt.savefig(f'plots/MST-density-{density}.png', bbox_inches='tight')
        plt.close()

def tsp_matrix(data):
    densities = [25, 50, 75, 99]

    for key, value in data:
        for density in densities:
            filtered_data = value[value['density'] == density]
            x = filtered_data['vertices']
            y = filtered_data['time']
            plt.plot(x, y, label = key.removesuffix('-matrix-Wyniki.csv') + ' ' + str(density) + '%', marker='.')

    plt.xlabel('vertices')
    plt.ylabel('time [us]')
    plt.title('TSP matrix')
    plt.legend()
    plt.savefig('plots/TSP-matrix.png', bbox_inches='tight')
    plt.close()

def tsp_list(data):
    densities = [25, 50, 75, 99]

    for key, value in data:
        for density in densities:
            filtered_data = value[value['density'] == density]
            x = filtered_data['vertices']
            y = filtered_data['time']
            plt.plot(x, y, label = key.removesuffix('-list-Wyniki.csv') + ' ' + str(density) + '%', marker='.')

    plt.xlabel('vertices')
    plt.ylabel('time [us]')
    plt.title('TSP list')
    plt.legend()
    plt.savefig('plots/TSP-list.png', bbox_inches='tight')
    plt.close()

def tsp_density(data):
    densities = [25, 50, 75, 99]

    for density in densities:
        for key, value in data:
            filtered_data = value[value['density'] == density]
            x = filtered_data['vertices']
            y = filtered_data['time']
            plt.plot(x, y, label = key.removesuffix('-Wyniki.csv'), marker='.')
        plt.xlabel('vertices')
        plt.ylabel('time [us]')
        plt.title(f'TSP density: {density}%')
        plt.legend()
        plt.savefig(f'plots/TSP-density-{density}.png', bbox_inches='tight')
        plt.close()

def main():
    files = [
        'prim-matrix-Wyniki.csv',
        'prim-list-Wyniki.csv',
        'kruskal-matrix-Wyniki.csv',
        'kruskal-list-Wyniki.csv',
        'dijkstra-matrix-Wyniki.csv',
        'dijkstra-list-Wyniki.csv',
        'bellman-ford-matrix-Wyniki.csv',
        'bellman-ford-list-Wyniki.csv'
    ]
    headers = ['vertices', 'density', 'time']

    all_data = {}

    for file in files:
        data = pd.read_csv(file, sep = ';')
        all_data[file] = data
    
    data_mst_matrix = [data for data in all_data.items() if 'matrix' in data[0] and ('prim' in data[0] or 'kruskal' in data[0])]
    mst_matrix(data_mst_matrix)

    data_mst_list = [data for data in all_data.items() if 'list' in data[0] and ('prim' in data[0] or 'kruskal' in data[0])]
    mst_list(data_mst_list)

    data_mst_density = [data for data in all_data.items() if 'prim' in data[0] or 'kruskal' in data[0]]
    mst_density(data_mst_density)

    data_tsp_matrix = [data for data in all_data.items() if 'matrix' in data[0] and ('dijkstra' in data[0] or 'bellman-ford' in data[0])]
    tsp_matrix(data_tsp_matrix)

    data_tsp_list = [data for data in all_data.items() if 'list' in data[0] and ('dijkstra' in data[0] or 'bellman-ford' in data[0])]
    tsp_list(data_tsp_list)

    data_tsp_density = [data for data in all_data.items() if 'dijkstra' in data[0] or 'bellman-ford' in data[0]]
    tsp_density(data_tsp_density)

if __name__ == '__main__':
    main()
#include "FordFulkerson.h"
#include <iostream>
#include <limits>
#include <queue>
#include <chrono>

using namespace std;

bool bfs(int** rGraph, int liczbaWierzcholkow, int start, int koniec, int parent[]) {
    bool* visited = new bool[liczbaWierzcholkow];
    for (int i = 0; i < liczbaWierzcholkow; ++i) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < liczbaWierzcholkow; ++v) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == koniec) {
                    parent[v] = u;
                    delete[] visited;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    delete[] visited;
    return false;
}

int FordFulkerson::uruchomDlaListy(const ListaSasiedztwa& graf, int start, int koniec) {
    auto start_time = chrono::high_resolution_clock::now(); // Start pomiaru czasu

    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int** rGraph = new int*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        rGraph[i] = new int[liczbaWierzcholkow];
        for (size_t j = 0; j < liczbaWierzcholkow; ++j) {
            rGraph[i][j] = 0;
        }
    }

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        const Krawedz* krawedz = graf.getSasiedzi(u);
        while (krawedz != nullptr) {
            rGraph[u][krawedz->koniec] = krawedz->wartosc;
            krawedz = krawedz->nastepna;
        }
    }

    int* parent = new int[liczbaWierzcholkow];
    int maxFlow = 0;

    while (bfs(rGraph, liczbaWierzcholkow, start, koniec, parent)) {
        int pathFlow = numeric_limits<int>::max();
        for (int v = koniec; v != start; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = koniec; v != start; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    auto stop_time = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    cout << "Czas dzialania algorytmu Forda-Fulkersona (Lista Sasiedztwa): " << duration.count() << " mikrosekund" << endl;

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        delete[] rGraph[i];
    }
    delete[] rGraph;
    delete[] parent;

    return maxFlow;
}

int FordFulkerson::uruchomDlaMacierzy(const MacierzIncydencji& graf, int start, int koniec) {
    auto start_time = chrono::high_resolution_clock::now(); // Start pomiaru czasu

    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int** rGraph = new int*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        rGraph[i] = new int[liczbaWierzcholkow];
        for (size_t j = 0; j < liczbaWierzcholkow; ++j) {
            rGraph[i][j] = 0;
        }
    }

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            int waga = graf.pobierzWage(u, v);
            if (waga != -1) {
                rGraph[u][v] = waga;
            }
        }
    }

    int* parent = new int[liczbaWierzcholkow];
    int maxFlow = 0;

    while (bfs(rGraph, liczbaWierzcholkow, start, koniec, parent)) {
        int pathFlow = numeric_limits<int>::max();
        for (int v = koniec; v != start; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = koniec; v != start; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    auto stop_time = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    cout << "Czas dzialania algorytmu Forda-Fulkersona (Macierz Incydencji): " << duration.count() << " mikrosekund" << endl;

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        delete[] rGraph[i];
    }
    delete[] rGraph;
    delete[] parent;

    return maxFlow;
}

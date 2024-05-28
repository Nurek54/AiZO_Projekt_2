#include "Dijkstra.h"
#include <iostream>
#include <limits>

void Dijkstra::uruchomDlaListy(const ListaSasiedztwa& graf, int start) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int* odleglosc = new int[liczbaWierzcholkow];
    bool* odwiedzone = new bool[liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        odleglosc[i] = std::numeric_limits<int>::max();
        odwiedzone[i] = false;
    }

    odleglosc[start] = 0;

    for (size_t count = 0; count < liczbaWierzcholkow - 1; ++count) {
        int min = std::numeric_limits<int>::max(), minIndex;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            if (!odwiedzone[v] && odleglosc[v] <= min) {
                min = odleglosc[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        odwiedzone[u] = true;

        const Krawedz* krawedz = graf.getSasiedzi(u);
        while (krawedz != nullptr) {
            int v = krawedz->koniec;
            if (!odwiedzone[v] && odleglosc[u] != std::numeric_limits<int>::max() && odleglosc[u] + krawedz->wartosc < odleglosc[v]) {
                odleglosc[v] = odleglosc[u] + krawedz->wartosc;
            }
            krawedz = krawedz->nastepna;
        }
    }

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        std::cout << "Odleglosc od " << start << " do " << i << " wynosi " << odleglosc[i] << std::endl;
    }

    delete[] odleglosc;
    delete[] odwiedzone;
}

void Dijkstra::uruchomDlaMacierzy(const MacierzIncydencji& graf, int start) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int* odleglosc = new int[liczbaWierzcholkow];
    bool* odwiedzone = new bool[liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        odleglosc[i] = std::numeric_limits<int>::max();
        odwiedzone[i] = false;
    }

    odleglosc[start] = 0;

    for (size_t count = 0; count < liczbaWierzcholkow - 1; ++count) {
        int min = std::numeric_limits<int>::max(), minIndex;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            if (!odwiedzone[v] && odleglosc[v] <= min) {
                min = odleglosc[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        odwiedzone[u] = true;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            int waga = graf.pobierzWage(u, v);
            if (waga != -1 && !odwiedzone[v] && odleglosc[u] != std::numeric_limits<int>::max() && odleglosc[u] + waga < odleglosc[v]) {
                odleglosc[v] = odleglosc[u] + waga;
            }
        }
    }

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        std::cout << "Odleglosc od " << start << " do " << i << " wynosi " << odleglosc[i] << std::endl;
    }

    delete[] odleglosc;
    delete[] odwiedzone;
}

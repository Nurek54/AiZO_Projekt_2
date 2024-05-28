#include "BellmanFord.h"
#include <iostream>
#include <limits>

void BellmanFord::uruchomDlaListy(const ListaSasiedztwa& graf, int start) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    size_t liczbaKrawedzi = graf.pobierzLiczbeKrawedzi();

    int* odleglosc = new int[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        odleglosc[i] = std::numeric_limits<int>::max();
    }
    odleglosc[start] = 0;

    Krawedz* krawedzie = new Krawedz[liczbaKrawedzi];
    size_t indeks = 0;

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        const Krawedz* krawedz = graf.pobierzKrawedzie()[u];
        while (krawedz != nullptr) {
            krawedzie[indeks++] = *krawedz;
            krawedz = krawedz->nastepna;
        }
    }

    for (size_t i = 1; i < liczbaWierzcholkow; ++i) {
        for (size_t j = 0; j < liczbaKrawedzi; ++j) {
            int u = krawedzie[j].poczatek;
            int v = krawedzie[j].koniec;
            int waga = krawedzie[j].wartosc;
            if (odleglosc[u] != std::numeric_limits<int>::max() && odleglosc[u] + waga < odleglosc[v]) {
                odleglosc[v] = odleglosc[u] + waga;
            }
        }
    }

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        std::cout << "Odleglosc od " << start << " do " << i << " wynosi " << odleglosc[i] << std::endl;
    }

    delete[] odleglosc;
    delete[] krawedzie;
}

void BellmanFord::uruchomDlaMacierzy(const MacierzIncydencji& graf, int start) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    size_t liczbaKrawedzi = graf.pobierzLiczbeKrawedzi();

    int* odleglosc = new int[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        odleglosc[i] = std::numeric_limits<int>::max();
    }
    odleglosc[start] = 0;

    Krawedz* krawedzie = new Krawedz[liczbaKrawedzi];
    size_t indeks = 0;

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            int waga = graf.pobierzWage(u, v);
            if (waga != -1) {
                krawedzie[indeks++] = {u, v, static_cast<size_t>(waga)};
            }
        }
    }

    for (size_t i = 1; i < liczbaWierzcholkow; ++i) {
        for (size_t j = 0; j < liczbaKrawedzi; ++j) {
            int u = krawedzie[j].poczatek;
            int v = krawedzie[j].koniec;
            int waga = krawedzie[j].wartosc;
            if (odleglosc[u] != std::numeric_limits<int>::max() && odleglosc[u] + waga < odleglosc[v]) {
                odleglosc[v] = odleglosc[u] + waga;
            }
        }
    }

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        std::cout << "Odleglosc od " << start << " do " << i << " wynosi " << odleglosc[i] << std::endl;
    }

    delete[] odleglosc;
    delete[] krawedzie;
}

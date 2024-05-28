#include "Prim.h"
#include <iostream>
#include <limits>

void Prim::uruchomDlaListy(const ListaSasiedztwa& graf) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();

    int* klucz = new int[liczbaWierzcholkow];
    int* rodzic = new int[liczbaWierzcholkow];
    bool* wMST = new bool[liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        klucz[i] = std::numeric_limits<int>::max();
        rodzic[i] = -1;
        wMST[i] = false;
    }

    klucz[0] = 0;

    for (size_t count = 0; count < liczbaWierzcholkow - 1; ++count) {
        int min = std::numeric_limits<int>::max(), minIndex;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            if (!wMST[v] && klucz[v] < min) {
                min = klucz[v];
                minIndex = v;
            }
        }

        wMST[minIndex] = true;

        const Krawedz* krawedz = graf.getSasiedzi(minIndex);
        while (krawedz != nullptr) {
            size_t v = krawedz->koniec;
            if (!wMST[v] && krawedz->wartosc < klucz[v]) {
                rodzic[v] = minIndex;
                klucz[v] = krawedz->wartosc;
            }
            krawedz = krawedz->nastepna;
        }
    }

    for (size_t i = 1; i < liczbaWierzcholkow; ++i) {
        std::cout << rodzic[i] << " - " << i << std::endl;
    }

    delete[] klucz;
    delete[] rodzic;
    delete[] wMST;
}

void Prim::uruchomDlaMacierzy(const MacierzIncydencji& graf) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();

    int* klucz = new int[liczbaWierzcholkow];
    int* rodzic = new int[liczbaWierzcholkow];
    bool* wMST = new bool[liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        klucz[i] = std::numeric_limits<int>::max();
        rodzic[i] = -1;
        wMST[i] = false;
    }

    klucz[0] = 0;

    for (size_t count = 0; count < liczbaWierzcholkow - 1; ++count) {
        int min = std::numeric_limits<int>::max(), minIndex;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            if (!wMST[v] && klucz[v] < min) {
                min = klucz[v];
                minIndex = v;
            }
        }

        wMST[minIndex] = true;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            int waga = graf.pobierzWage(minIndex, v);
            if (waga != -1 && !wMST[v] && waga < klucz[v]) {
                rodzic[v] = minIndex;
                klucz[v] = waga;
            }
        }
    }

    for (size_t i = 1; i < liczbaWierzcholkow; ++i) {
        std::cout << rodzic[i] << " - " << i << std::endl;
    }

    delete[] klucz;
    delete[] rodzic;
    delete[] wMST;
}

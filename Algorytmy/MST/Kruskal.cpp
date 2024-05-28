#include "Kruskal.h"
#include <iostream>
#include <algorithm>

void Kruskal::uruchomDlaListy(const ListaSasiedztwa& graf) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    size_t liczbaKrawedzi = graf.pobierzLiczbeKrawedzi();

    Krawedz* krawedzie = new Krawedz[liczbaKrawedzi];
    size_t indeks = 0;

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        const Krawedz* krawedz = graf.pobierzKrawedzie()[u];
        while (krawedz != nullptr) {
            krawedzie[indeks++] = *krawedz;
            krawedz = krawedz->nastepna;
        }
    }

    std::sort(krawedzie, krawedzie + liczbaKrawedzi, [](const Krawedz& a, const Krawedz& b) {
        return a.wartosc < b.wartosc;
    });

    size_t* identyfikatoryDrzew = new size_t[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        identyfikatoryDrzew[i] = i;
    }

    size_t* wynikBufor = new size_t[(liczbaWierzcholkow - 1) * 3];
    size_t wynikIndeks = 0;

    indeks = 0;
    while (wynikIndeks < liczbaWierzcholkow - 1 && indeks < liczbaKrawedzi) {
        Krawedz nastepnaKrawedz = krawedzie[indeks++];

        size_t x = identyfikatoryDrzew[nastepnaKrawedz.poczatek];
        size_t y = identyfikatoryDrzew[nastepnaKrawedz.koniec];

        if (x != y) {
            wynikBufor[3 * wynikIndeks] = nastepnaKrawedz.poczatek;
            wynikBufor[3 * wynikIndeks + 1] = nastepnaKrawedz.koniec;
            wynikBufor[3 * wynikIndeks + 2] = nastepnaKrawedz.wartosc;

            for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
                if (identyfikatoryDrzew[i] == x) {
                    identyfikatoryDrzew[i] = y;
                }
            }

            wynikIndeks++;
        }
    }

    std::cout << "Minimalne Drzewo Rozpinające (Lista Sąsiedztwa):" << std::endl;
    for (size_t i = 0; i < wynikIndeks; ++i) {
        std::cout << "Krawędź: " << wynikBufor[3 * i] << " - " << wynikBufor[3 * i + 1] << " Waga: " << wynikBufor[3 * i + 2] << std::endl;
    }

    delete[] krawedzie;
    delete[] identyfikatoryDrzew;
    delete[] wynikBufor;
}

void Kruskal::uruchomDlaMacierzy(const MacierzIncydencji& graf) {
    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    size_t liczbaKrawedzi = graf.pobierzLiczbeKrawedzi();

    Krawedz* krawedzie = new Krawedz[liczbaKrawedzi];
    size_t indeks = 0;

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            int waga = graf.pobierzWage(u, v);
            if (waga != -1) {
                krawedzie[indeks++] = {u, v, (size_t)waga};
            }
        }
    }

    std::sort(krawedzie, krawedzie + liczbaKrawedzi, [](const Krawedz& a, const Krawedz& b) {
        return a.wartosc < b.wartosc;
    });

    size_t* identyfikatoryDrzew = new size_t[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        identyfikatoryDrzew[i] = i;
    }

    size_t* wynikBufor = new size_t[(liczbaWierzcholkow - 1) * 3];
    size_t wynikIndeks = 0;

    indeks = 0;
    while (wynikIndeks < liczbaWierzcholkow - 1 && indeks < liczbaKrawedzi) {
        Krawedz nastepnaKrawedz = krawedzie[indeks++];

        size_t x = identyfikatoryDrzew[nastepnaKrawedz.poczatek];
        size_t y = identyfikatoryDrzew[nastepnaKrawedz.koniec];

        if (x != y) {
            wynikBufor[3 * wynikIndeks] = nastepnaKrawedz.poczatek;
            wynikBufor[3 * wynikIndeks + 1] = nastepnaKrawedz.koniec;
            wynikBufor[3 * wynikIndeks + 2] = nastepnaKrawedz.wartosc;

            for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
                if (identyfikatoryDrzew[i] == x) {
                    identyfikatoryDrzew[i] = y;
                }
            }

            wynikIndeks++;
        }
    }

    std::cout << "Minimalne Drzewo Rozpinające (Macierz Incydencji):" << std::endl;
    for (size_t i = 0; i < wynikIndeks; ++i) {
        std::cout << "Krawędź: " << wynikBufor[3 * i] << " - " << wynikBufor[3 * i + 1] << " Waga: " << wynikBufor[3 * i + 2] << std::endl;
    }

    delete[] krawedzie;
    delete[] identyfikatoryDrzew;
    delete[] wynikBufor;
}

#include "Kruskal.h"
#include <iostream>
#include <chrono>

using namespace std;

void Kruskal::selectionSort(Krawedz* krawedzie, size_t liczbaKrawedzi) {
    for (size_t i = 0; i < liczbaKrawedzi - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < liczbaKrawedzi; ++j) {
            if (krawedzie[j].wartosc < krawedzie[minIdx].wartosc) {
                minIdx = j;
            }
        }
        // Zamiana miejscami
        Krawedz temp = krawedzie[i];
        krawedzie[i] = krawedzie[minIdx];
        krawedzie[minIdx] = temp;
    }
}

void Kruskal::uruchomDlaListy(const ListaSasiedztwa& graf) {
    auto start_time = chrono::high_resolution_clock::now(); // Start pomiaru czasu

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

    // Sortowanie krawędzi za pomocą sortowania przez wybór
    selectionSort(krawedzie, liczbaKrawedzi);

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

    auto stop_time = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    cout << "Czas dzialania algorytmu Kruskala (Lista Sasiedztwa): " << duration.count() << " mikrosekund" << endl;

    cout << "Minimalne Drzewo Rozpinające (Lista Sasiedztwa):" << endl;
    for (size_t i = 0; i < wynikIndeks; ++i) {
        cout << "Krawedz: " << wynikBufor[3 * i] << " - " << wynikBufor[3 * i + 1] << " Waga: " << wynikBufor[3 * i + 2] << endl;
    }

    delete[] krawedzie;
    delete[] identyfikatoryDrzew;
    delete[] wynikBufor;
}

void Kruskal::uruchomDlaMacierzy(const MacierzIncydencji& graf) {
    auto start_time = chrono::high_resolution_clock::now(); // Start pomiaru czasu

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

    // Sortowanie krawędzi za pomocą sortowania przez wybór
    selectionSort(krawedzie, liczbaKrawedzi);

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

    auto stop_time = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    cout << "Czas dzialania algorytmu Kruskala (Macierz Incydencji): " << duration.count() << " mikrosekund" << endl;

    cout << "Minimalne Drzewo Rozpinające (Macierz Incydencji):" << endl;
    for (size_t i = 0; i < wynikIndeks; ++i) {
        cout << "Krawędz: " << wynikBufor[3 * i] << " - " << wynikBufor[3 * i + 1] << " Waga: " << wynikBufor[3 * i + 2] << endl;
    }

    delete[] krawedzie;
    delete[] identyfikatoryDrzew;
    delete[] wynikBufor;
}

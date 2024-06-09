#include "FordFulkerson.h"
#include <iostream>
#include <limits>
#include <chrono>

using namespace std;

class ProstaKolejka {
    int* dane;
    int pojemnosc;
    int przod;
    int tyl;
    int liczbaElementow;

public:
    ProstaKolejka(int rozmiar) : pojemnosc(rozmiar), przod(0), tyl(0), liczbaElementow(0) {
        dane = new int[pojemnosc];
    }

    ~ProstaKolejka() {
        delete[] dane;
    }

    void wstaw(int wartosc) {
        if (liczbaElementow == pojemnosc) return; // kolejka jest pelna
        dane[tyl] = wartosc;
        tyl = (tyl + 1) % pojemnosc;
        ++liczbaElementow;
    }

    void usun() {
        if (liczbaElementow == 0) return; // kolejka jest pusta
        przod = (przod + 1) % pojemnosc;
        --liczbaElementow;
    }

    int przodWartosc() const {
        return dane[przod];
    }

    bool pusta() const {
        return liczbaElementow == 0;
    }
};

bool bfs(int** rGraf, int liczbaWierzcholkow, int start, int koniec, int rodzic[]) {
    bool* odwiedzone = new bool[liczbaWierzcholkow];
    for (int i = 0; i < liczbaWierzcholkow; ++i) {
        odwiedzone[i] = false;
    }

    ProstaKolejka q(liczbaWierzcholkow);
    q.wstaw(start);
    odwiedzone[start] = true;
    rodzic[start] = -1;

    while (!q.pusta()) {
        int u = q.przodWartosc();
        q.usun();

        for (int v = 0; v < liczbaWierzcholkow; ++v) {
            if (!odwiedzone[v] && rGraf[u][v] > 0) {
                if (v == koniec) {
                    rodzic[v] = u;
                    delete[] odwiedzone;
                    return true;
                }
                q.wstaw(v);
                rodzic[v] = u;
                odwiedzone[v] = true;
            }
        }
    }

    delete[] odwiedzone;
    return false;
}

int FordFulkerson::uruchomDlaListy(const ListaSasiedztwa& graf, int start, int koniec) {
    auto czas_start = chrono::high_resolution_clock::now(); // Start pomiaru czasu

    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int** rGraf = new int*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        rGraf[i] = new int[liczbaWierzcholkow];
        for (size_t j = 0; j < liczbaWierzcholkow; ++j) {
            rGraf[i][j] = 0;
        }
    }

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        const Krawedz* krawedz = graf.getSasiedzi(u);
        while (krawedz != nullptr) {
            rGraf[u][krawedz->koniec] = krawedz->wartosc;
            krawedz = krawedz->nastepna;
        }
    }

    int* rodzic = new int[liczbaWierzcholkow];
    int maxPrzeplyw = 0;

    while (bfs(rGraf, liczbaWierzcholkow, start, koniec, rodzic)) {
        int przeplywSciezki = numeric_limits<int>::max();
        for (int v = koniec; v != start; v = rodzic[v]) {
            int u = rodzic[v];
            przeplywSciezki = min(przeplywSciezki, rGraf[u][v]);
        }

        for (int v = koniec; v != start; v = rodzic[v]) {
            int u = rodzic[v];
            rGraf[u][v] -= przeplywSciezki;
            rGraf[v][u] += przeplywSciezki;
        }

        maxPrzeplyw += przeplywSciezki;
    }

    auto czas_stop = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto czas_trwania = chrono::duration_cast<chrono::microseconds>(czas_stop - czas_start);
    cout << "Czas dzialania algorytmu Forda-Fulkersona (Lista Sasiedztwa): " << czas_trwania.count() << " mikrosekund" << endl;

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        delete[] rGraf[i];
    }
    delete[] rGraf;
    delete[] rodzic;

    return maxPrzeplyw;
}

int FordFulkerson::uruchomDlaMacierzy(const MacierzIncydencji& graf, int start, int koniec) {
    auto czas_start = chrono::high_resolution_clock::now(); // Start pomiaru czasu

    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int** rGraf = new int*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        rGraf[i] = new int[liczbaWierzcholkow];
        for (size_t j = 0; j < liczbaWierzcholkow; ++j) {
            rGraf[i][j] = 0;
        }
    }

    for (size_t u = 0; u < liczbaWierzcholkow; ++u) {
        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            int waga = graf.pobierzWage(u, v);
            if (waga != -1) {
                rGraf[u][v] = waga;
            }
        }
    }

    int* rodzic = new int[liczbaWierzcholkow];
    int maxPrzeplyw = 0;

    while (bfs(rGraf, liczbaWierzcholkow, start, koniec, rodzic)) {
        int przeplywSciezki = numeric_limits<int>::max();
        for (int v = koniec; v != start; v = rodzic[v]) {
            int u = rodzic[v];
            przeplywSciezki = min(przeplywSciezki, rGraf[u][v]);
        }

        for (int v = koniec; v != start; v = rodzic[v]) {
            int u = rodzic[v];
            rGraf[u][v] -= przeplywSciezki;
            rGraf[v][u] += przeplywSciezki;
        }

        maxPrzeplyw += przeplywSciezki;
    }

    auto czas_stop = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto czas_trwania = chrono::duration_cast<chrono::microseconds>(czas_stop - czas_start);
    cout << "Czas dzialania algorytmu Forda-Fulkersona (Macierz Incydencji): " << czas_trwania.count() << " mikrosekund" << endl;

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        delete[] rGraf[i];
    }
    delete[] rGraf;
    delete[] rodzic;

    return maxPrzeplyw;
}

#include "GeneratorGrafow.h"
#include <cstdlib>
#include <ctime>

using namespace std;

SuroweDaneGrafu GeneratorGrafow::generuj(float gestosc, size_t liczbaWierzcholkow, size_t maxWartosc) {
    srand(static_cast<unsigned int>(time(nullptr))); // Inicjalizacja generatora liczb losowych

    size_t minimalnaLiczbaKrawedzi = liczbaWierzcholkow;
    size_t liczbaKrawedzi = static_cast<size_t>((gestosc * liczbaWierzcholkow * (liczbaWierzcholkow - 1)) / 2);
    liczbaKrawedzi = liczbaKrawedzi > minimalnaLiczbaKrawedzi ? liczbaKrawedzi : minimalnaLiczbaKrawedzi;
    size_t rozmiarDanych = 3 * liczbaKrawedzi;
    size_t* dane = new size_t[rozmiarDanych];

    bool** polaczeniaIstnieja = new bool*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; i++) {
        polaczeniaIstnieja[i] = new bool[liczbaWierzcholkow]();
    }

    for (size_t i = 0; i < minimalnaLiczbaKrawedzi - 1; i++) {
        dane[3 * i] = i;
        dane[3 * i + 1] = i + 1;
        dane[3 * i + 2] = rand() % maxWartosc + 1;
        polaczeniaIstnieja[i][i + 1] = true;
        polaczeniaIstnieja[i + 1][i] = true;
    }

    dane[3 * (minimalnaLiczbaKrawedzi - 1)] = minimalnaLiczbaKrawedzi - 1;
    dane[3 * (minimalnaLiczbaKrawedzi - 1) + 1] = 0;
    dane[3 * (minimalnaLiczbaKrawedzi - 1) + 2] = rand() % maxWartosc + 1;
    polaczeniaIstnieja[minimalnaLiczbaKrawedzi - 1][0] = true;
    polaczeniaIstnieja[0][minimalnaLiczbaKrawedzi - 1] = true;

    for (size_t i = minimalnaLiczbaKrawedzi; i < liczbaKrawedzi; i++) {
        size_t poczatek = rand() % liczbaWierzcholkow;
        size_t koniec = rand() % liczbaWierzcholkow;

        while (poczatek == koniec || polaczeniaIstnieja[poczatek][koniec]) {
            poczatek = rand() % liczbaWierzcholkow;
            koniec = rand() % liczbaWierzcholkow;
        }

        dane[3 * i] = poczatek;
        dane[3 * i + 1] = koniec;
        dane[3 * i + 2] = rand() % maxWartosc + 1;

        polaczeniaIstnieja[poczatek][koniec] = true;
        polaczeniaIstnieja[koniec][poczatek] = true;
    }

    for (size_t i = 0; i < liczbaWierzcholkow; i++) {
        delete[] polaczeniaIstnieja[i];
    }
    delete[] polaczeniaIstnieja;

    SuroweDaneGrafu wynik;
    wynik.dane = dane;
    wynik.liczbaWierzcholkow = liczbaWierzcholkow;
    wynik.liczbaKrawedzi = liczbaKrawedzi;

    return wynik;
}

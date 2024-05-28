#include "GeneratorGrafow.h"

SuroweDaneGrafu GeneratorGrafow::generuj(float gestosc, size_t liczbaWierzcholkow, size_t maxWartosc) {
    size_t minimalnaLiczbaKrawedzi = liczbaWierzcholkow;
    size_t liczbaKrawedzi = (gestosc * liczbaWierzcholkow * (liczbaWierzcholkow - 1)) / 2;
    liczbaKrawedzi = liczbaKrawedzi > minimalnaLiczbaKrawedzi ? liczbaKrawedzi : minimalnaLiczbaKrawedzi;
    size_t rozmiarDanych = 3 * liczbaKrawedzi;
    size_t* dane = new size_t[rozmiarDanych];

    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<size_t> wartosci(1, maxWartosc);
    std::uniform_int_distribution<size_t> wierzcholki(0, liczbaWierzcholkow - 1);

    bool** polaczeniaIstnieja = new bool*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; i++) {
        polaczeniaIstnieja[i] = new bool[liczbaWierzcholkow]();
    }

    for (size_t i = 0; i < minimalnaLiczbaKrawedzi - 1; i++) {
        dane[3 * i] = i;
        dane[3 * i + 1] = i + 1;
        dane[3 * i + 2] = wartosci(gen);
        polaczeniaIstnieja[i][i + 1] = true;
        polaczeniaIstnieja[i + 1][i] = true;
    }

    dane[3 * (minimalnaLiczbaKrawedzi - 1)] = minimalnaLiczbaKrawedzi - 1;
    dane[3 * (minimalnaLiczbaKrawedzi - 1) + 1] = 0;
    dane[3 * (minimalnaLiczbaKrawedzi - 1) + 2] = wartosci(gen);
    polaczeniaIstnieja[minimalnaLiczbaKrawedzi - 1][0] = true;
    polaczeniaIstnieja[0][minimalnaLiczbaKrawedzi - 1] = true;

    for (size_t i = minimalnaLiczbaKrawedzi; i < liczbaKrawedzi; i++) {
        size_t poczatek = wierzcholki(gen);
        size_t koniec = wierzcholki(gen);

        while (poczatek == koniec || polaczeniaIstnieja[poczatek][koniec]) {
            poczatek = wierzcholki(gen);
            koniec = wierzcholki(gen);
        }

        dane[3 * i] = poczatek;
        dane[3 * i + 1] = koniec;
        dane[3 * i + 2] = wartosci(gen);

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

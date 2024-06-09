#include "CzytnikGrafow.h"
#include <fstream>

using namespace std;

CzytnikGrafow::CzytnikGrafow(string sciezkaBazowa) : sciezkaBazowa(sciezkaBazowa) {}

MacierzIncydencji* CzytnikGrafow::wczytajMacierz(string nazwaPliku) {
    size_t liczbaKrawedzi, liczbaWierzcholkow;
    size_t* dane;

    if (!this->wczytajDane(nazwaPliku, liczbaKrawedzi, liczbaWierzcholkow, dane)) {
        return nullptr;
    }

    MacierzIncydencji* macierz = new MacierzIncydencji(liczbaKrawedzi, liczbaWierzcholkow, dane);

    delete[] dane;

    return macierz;
}

ListaSasiedztwa* CzytnikGrafow::wczytajListe(string nazwaPliku) {
    size_t liczbaKrawedzi, liczbaWierzcholkow;
    size_t* dane;

    if (!this->wczytajDane(nazwaPliku, liczbaKrawedzi, liczbaWierzcholkow, dane)) {
        return nullptr;
    }

    ListaSasiedztwa* lista = new ListaSasiedztwa(liczbaKrawedzi, liczbaWierzcholkow, dane);

    delete[] dane;

    return lista;
}

bool CzytnikGrafow::wczytajDane(string nazwaPliku, size_t& liczbaKrawedzi, size_t& liczbaWierzcholkow, size_t*& dane) {
    ifstream plik(this->sciezkaBazowa + nazwaPliku);

    if (plik.fail()) {
        return false;
    }

    plik >> liczbaKrawedzi >> liczbaWierzcholkow;

    size_t rozmiarDanych = liczbaKrawedzi * 3;
    dane = new size_t[rozmiarDanych];

    for (size_t i = 0; i < rozmiarDanych; i++) {
        plik >> dane[i];
    }

    return true;
}

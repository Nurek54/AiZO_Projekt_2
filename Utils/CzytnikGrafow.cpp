#include "CzytnikGrafow.h"
#include <fstream>

using namespace std;

CzytnikGrafow::CzytnikGrafow(string sciezkaBazowa) : sciezkaBazowa(sciezkaBazowa) {}

MacierzIncydencji* CzytnikGrafow::wczytajMacierz(string nazwaPliku) {
    size_t liczbaKrawedzi, liczbaWierzcholkow;
    size_t* dane;

    tie(liczbaKrawedzi, liczbaWierzcholkow, dane) = this->wczytajDane(nazwaPliku);

    if (dane == nullptr) {
        return nullptr;
    }

    MacierzIncydencji* macierz = new MacierzIncydencji(liczbaKrawedzi, liczbaWierzcholkow, dane);

    delete[] dane;

    return macierz;
}

ListaSasiedztwa* CzytnikGrafow::wczytajListe(string nazwaPliku) {
    size_t liczbaKrawedzi, liczbaWierzcholkow;
    size_t* dane;

    tie(liczbaKrawedzi, liczbaWierzcholkow, dane) = this->wczytajDane(nazwaPliku);

    if (dane == nullptr) {
        return nullptr;
    }

    ListaSasiedztwa* lista = new ListaSasiedztwa(liczbaKrawedzi, liczbaWierzcholkow, dane);

    delete[] dane;

    return lista;
}

tuple<size_t, size_t, size_t*> CzytnikGrafow::wczytajDane(string nazwaPliku) {
    ifstream plik(this->sciezkaBazowa + nazwaPliku);

    if (plik.fail()) {
        return make_tuple(-1, -1, nullptr);
    }

    size_t liczbaKrawedzi, liczbaWierzcholkow;

    plik >> liczbaKrawedzi >> liczbaWierzcholkow;

    size_t rozmiarDanych = liczbaKrawedzi * 3;
    size_t* dane = new size_t[rozmiarDanych];

    for (size_t i = 0; i < rozmiarDanych; i++) {
        plik >> dane[i];
    }

    return make_tuple(liczbaKrawedzi, liczbaWierzcholkow, dane);
}

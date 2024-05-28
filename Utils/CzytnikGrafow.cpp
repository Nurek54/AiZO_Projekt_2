#include "CzytnikGrafow.h"
#include <fstream>

CzytnikGrafow::CzytnikGrafow(std::string sciezkaBazowa) : sciezkaBazowa(sciezkaBazowa) {}

MacierzIncydencji* CzytnikGrafow::wczytajMacierz(std::string nazwaPliku) {
    size_t liczbaKrawedzi, liczbaWierzcholkow;
    size_t* dane;

    std::tie(liczbaKrawedzi, liczbaWierzcholkow, dane) = this->wczytajDane(nazwaPliku);

    if (dane == nullptr) {
        return nullptr;
    }

    MacierzIncydencji* macierz = new MacierzIncydencji(liczbaKrawedzi, liczbaWierzcholkow, dane);

    delete[] dane;

    return macierz;
}

ListaSasiedztwa* CzytnikGrafow::wczytajListe(std::string nazwaPliku) {
    size_t liczbaKrawedzi, liczbaWierzcholkow;
    size_t* dane;

    std::tie(liczbaKrawedzi, liczbaWierzcholkow, dane) = this->wczytajDane(nazwaPliku);

    if (dane == nullptr) {
        return nullptr;
    }

    ListaSasiedztwa* lista = new ListaSasiedztwa(liczbaKrawedzi, liczbaWierzcholkow, dane);

    delete[] dane;

    return lista;
}

std::tuple<size_t, size_t, size_t*> CzytnikGrafow::wczytajDane(std::string nazwaPliku) {
    std::ifstream plik(this->sciezkaBazowa + nazwaPliku);

    if (plik.fail()) {
        return std::make_tuple(-1, -1, nullptr);
    }

    size_t liczbaKrawedzi, liczbaWierzcholkow;

    plik >> liczbaKrawedzi >> liczbaWierzcholkow;

    size_t rozmiarDanych = liczbaKrawedzi * 3;
    size_t* dane = new size_t[rozmiarDanych];

    for (size_t i = 0; i < rozmiarDanych; i++) {
        plik >> dane[i];
    }

    return std::make_tuple(liczbaKrawedzi, liczbaWierzcholkow, dane);
}

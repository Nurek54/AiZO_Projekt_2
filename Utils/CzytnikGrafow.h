#ifndef CZYTNIKGRAFOW_H
#define CZYTNIKGRAFOW_H

#include "../Tablica/MacierzIncydencji.h"
#include "../Tablica/ListaSasiedztwa.h"
#include <string>

using namespace std;

class CzytnikGrafow {
public:
    CzytnikGrafow(string sciezkaBazowa);

    MacierzIncydencji* wczytajMacierz(string nazwaPliku);
    ListaSasiedztwa* wczytajListe(string nazwaPliku);

private:
    bool wczytajDane(string nazwaPliku, size_t& liczbaKrawedzi, size_t& liczbaWierzcholkow, size_t*& dane);

    string sciezkaBazowa;
};

#endif // CZYTNIKGRAFOW_H

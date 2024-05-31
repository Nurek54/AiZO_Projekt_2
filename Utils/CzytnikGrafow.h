#ifndef CZYTNIKGRAFOW_H
#define CZYTNIKGRAFOW_H

#include "../Tablica/MacierzIncydencji.h"
#include "../Tablica/ListaSasiedztwa.h"
#include <string>
#include <tuple>

using namespace std;

class CzytnikGrafow {
public:
    CzytnikGrafow(string sciezkaBazowa);

    MacierzIncydencji* wczytajMacierz(string nazwaPliku);
    ListaSasiedztwa* wczytajListe(string nazwaPliku);

private:
    tuple<size_t, size_t, size_t*> wczytajDane(string nazwaPliku);

    string sciezkaBazowa;
};

#endif // CZYTNIKGRAFOW_H

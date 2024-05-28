#ifndef CZYTNIKGRAFOW_H
#define CZYTNIKGRAFOW_H

#include "../Tablica/MacierzIncydencji.h"
#include "../Tablica/ListaSasiedztwa.h"
#include <string>
#include <tuple>

class CzytnikGrafow {
public:
    CzytnikGrafow(std::string sciezkaBazowa);

    MacierzIncydencji* wczytajMacierz(std::string nazwaPliku);
    ListaSasiedztwa* wczytajListe(std::string nazwaPliku);

private:
    std::tuple<size_t, size_t, size_t*> wczytajDane(std::string nazwaPliku);

    std::string sciezkaBazowa;
};

#endif // CZYTNIKGRAFOW_H

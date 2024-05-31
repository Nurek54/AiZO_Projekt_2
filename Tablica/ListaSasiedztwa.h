#ifndef LISTASASIEDZTWA_H
#define LISTASASIEDZTWA_H

#include <iostream>
#include <iomanip>

using namespace std;

struct Krawedz {
    size_t poczatek;
    size_t koniec;
    size_t wartosc;
    Krawedz* nastepna;
    Krawedz* poprzednia;
};

class ListaSasiedztwa {
public:
    ListaSasiedztwa(size_t liczbaKrawedzi, size_t liczbaWierzcholkow, size_t* dane);
    ~ListaSasiedztwa();

    void drukuj(ostream& wyjscie) const;
    size_t pobierzLiczbeWierzcholkow() const;
    size_t pobierzLiczbeKrawedzi() const;
    Krawedz** pobierzKrawedzie() const;
    const Krawedz* getSasiedzi(size_t indeks) const;

private:
    size_t liczbaKrawedzi;
    size_t liczbaWierzcholkow;
    Krawedz** krawedzie;
};

#endif // LISTASASIEDZTWA_H
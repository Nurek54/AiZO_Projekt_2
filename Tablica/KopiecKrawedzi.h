#ifndef KOPIECKRAWEDZI_H
#define KOPIECKRAWEDZI_H

#include "ListaSasiedztwa.h"

class KopiecKrawedzi {
public:
    KopiecKrawedzi(bool czyscPrzyUsuwaniu = true);
    ~KopiecKrawedzi();

    void dodaj(Krawedz* krawedz);
    Krawedz* usun();
    bool jestPusty() const;
    void drukuj() const;

private:
    void naprawWGore();
    void naprawWDol();

    bool czyscPrzyUsuwaniu;
    size_t rozmiar;
    Krawedz** korzen;
};

#endif // KOPIECKRAWEDZI_H

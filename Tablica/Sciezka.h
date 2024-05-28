#ifndef SCIEZKA_H
#define SCIEZKA_H

#include "Tablica.h"
#include "KrawedzSciezki.h"
#include <iostream>

class Sciezka {
public:
    Sciezka();
    Sciezka(const Sciezka& sciezka);

    void dodajKrawedz(KrawedzSciezki krawedz);
    void drukuj(std::ostream& wyjscie) const;

private:
    Tablica<KrawedzSciezki> krawedzie;
    int calkowityKoszt;
};

#endif // SCIEZKA_H

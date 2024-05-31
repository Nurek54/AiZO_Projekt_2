#ifndef KRAWEDZSCIEZKI_H
#define KRAWEDZSCIEZKI_H

#include <iostream>

using namespace std;

class KrawedzSciezki {
public:
    int poczatek;
    int koniec;
    int wartosc;

    KrawedzSciezki() : poczatek(0), koniec(0), wartosc(0) {}  // Domyślny konstruktor
    KrawedzSciezki(int p, int k, int w) : poczatek(p), koniec(k), wartosc(w) {}

    // Deklaracja operatora <<
    friend ostream& operator<<(ostream& wyjscie, const KrawedzSciezki& krawedz);
};

ostream& operator<<(ostream& wyjscie, const KrawedzSciezki& krawedz);

#endif // KRAWEDZSCIEZKI_H

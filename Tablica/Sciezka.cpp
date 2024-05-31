#include "Sciezka.h"

using namespace std;

void Sciezka::dodajKrawedz(KrawedzSciezki krawedz) {
    this->calkowityKoszt += krawedz.wartosc;
    this->krawedzie.dodajNaPoczatek(krawedz);
}

void Sciezka::drukuj(ostream& wyjscie) const {
    this->krawedzie.drukuj(wyjscie);
    wyjscie << "Calkowity koszt: " << this->calkowityKoszt << endl;
}

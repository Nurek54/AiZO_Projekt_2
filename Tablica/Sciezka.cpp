#include "Sciezka.h"

void Sciezka::dodajKrawedz(KrawedzSciezki krawedz) {
    this->calkowityKoszt += krawedz.wartosc;
    this->krawedzie.dodajNaPoczatek(krawedz);
}

void Sciezka::drukuj(std::ostream& wyjscie) const {
    this->krawedzie.drukuj(wyjscie);
    wyjscie << "Calkowity koszt: " << this->calkowityKoszt << std::endl;
}

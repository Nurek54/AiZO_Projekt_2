#include "KrawedzSciezki.h"

std::ostream& operator<<(std::ostream& wyjscie, const KrawedzSciezki& krawedz) {
    wyjscie << "Poczatek: " << krawedz.poczatek << ", Koniec: " << krawedz.koniec << ", Wartosc: " << krawedz.wartosc;
    return wyjscie;
}

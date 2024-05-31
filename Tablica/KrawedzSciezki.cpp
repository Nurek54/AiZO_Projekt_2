#include "KrawedzSciezki.h"

using namespace std;

ostream& operator<<(ostream& wyjscie, const KrawedzSciezki& krawedz) {
    wyjscie << "Poczatek: " << krawedz.poczatek << ", Koniec: " << krawedz.koniec << ", Wartosc: " << krawedz.wartosc;
    return wyjscie;
}

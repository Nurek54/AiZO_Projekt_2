#include "KrawedzSciezki.h"

// Definicja funkcji przyjacielskiej operatora <<
// Funkcja ta przyjmuje strumień wyjściowy (ostream) oraz obiekt klasy KrawedzSciezki.
// Umożliwia to wypisanie wartości członków obiektu (poczatek, koniec, wartosc)
// w odpowiednim formacie do strumienia wyjściowego.
ostream& operator<<(ostream& wyjscie, const KrawedzSciezki& krawedz) {
    wyjscie << "Poczatek: " << krawedz.poczatek << ", Koniec: " << krawedz.koniec << ", Wartosc: " << krawedz.wartosc;
    return wyjscie;
}

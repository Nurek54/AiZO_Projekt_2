#ifndef KRAWEDZSCIEZKI_H
#define KRAWEDZSCIEZKI_H

#include <iostream>

using namespace std;

class KrawedzSciezki {
public:
    int poczatek;  // Punkt początkowy krawędzi
    int koniec;    // Punkt końcowy krawędzi
    int wartosc;   // Wartość (waga) krawędzi

    // Domyślny konstruktor - inicjalizuje krawędź o wartości 0
    KrawedzSciezki() : poczatek(0), koniec(0), wartosc(0) {}

    // Konstruktor parametryczny - inicjalizuje krawędź podanymi wartościami
    KrawedzSciezki(int p, int k, int w) : poczatek(p), koniec(k), wartosc(w) {}

    // Deklaracja funkcji przyjacielskiej operatora <<
    // Funkcja przyjacielska pozwala na dostęp do prywatnych i chronionych
    // członków klasy bez konieczności używania metod publicznych.
    // Funkcja ta umożliwia wypisywanie obiektów klasy KrawedzSciezki
    // bezpośrednio za pomocą operatora strumieniowego <<.
    // Dzięki temu możemy zrobić coś takiego:
    // KrawedzSciezki krawedz(1, 2, 10);
    // std::cout << krawedz;
    // Funkcja ta jest zdefiniowana poza ciałem klasy, ale ma dostęp do jej
    // prywatnych członków, ponieważ jest zadeklarowana jako przyjacielska.
    friend ostream& operator<<(ostream& wyjscie, const KrawedzSciezki& krawedz);
};

#endif // KRAWEDZSCIEZKI_H

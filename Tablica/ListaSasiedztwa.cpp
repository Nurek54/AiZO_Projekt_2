#include "ListaSasiedztwa.h"

using namespace std;

ListaSasiedztwa::ListaSasiedztwa(size_t liczbaKrawedzi, size_t liczbaWierzcholkow, size_t* dane)
        : liczbaKrawedzi(liczbaKrawedzi), liczbaWierzcholkow(liczbaWierzcholkow) {
    krawedzie = new Krawedz*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        krawedzie[i] = nullptr;
    }

    size_t liczbaDanych = 3 * liczbaKrawedzi;
    for (size_t i = 0; i < liczbaDanych; i += 3) {
        size_t poczatek = dane[i];
        size_t koniec = dane[i + 1];
        size_t wartosc = dane[i + 2];

        Krawedz* nowaKrawedz = new Krawedz{poczatek, koniec, wartosc, nullptr, nullptr};
        if (krawedzie[poczatek] == nullptr) {
            krawedzie[poczatek] = nowaKrawedz;
        } else {
            Krawedz* tmp = krawedzie[poczatek];
            while (tmp->nastepna != nullptr) {
                tmp = tmp->nastepna;
            }
            tmp->nastepna = nowaKrawedz;
            nowaKrawedz->poprzednia = tmp;
        }
    }
}

ListaSasiedztwa::~ListaSasiedztwa() {
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        Krawedz* krawedz = krawedzie[i];
        while (krawedz != nullptr) {
            Krawedz* doUsuniecia = krawedz;
            krawedz = krawedz->nastepna;
            delete doUsuniecia;
        }
    }
    delete[] krawedzie;
}

void ListaSasiedztwa::drukuj(ostream& wyjscie) const {
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        wyjscie << setw(2) << i << " --> ";
        Krawedz* krawedz = krawedzie[i];
        while (krawedz != nullptr) {
            wyjscie << setw(2) << krawedz->koniec << '[' << setw(2) << krawedz->wartosc << "] | ";
            krawedz = krawedz->nastepna;
        }
        wyjscie << endl;
    }
}

size_t ListaSasiedztwa::pobierzLiczbeWierzcholkow() const {
    return liczbaWierzcholkow;
}

size_t ListaSasiedztwa::pobierzLiczbeKrawedzi() const {
    return liczbaKrawedzi;
}

Krawedz** ListaSasiedztwa::pobierzKrawedzie() const {
    return krawedzie;
}

const Krawedz* ListaSasiedztwa::getSasiedzi(size_t indeks) const {
    if (indeks < liczbaWierzcholkow) {
        return krawedzie[indeks];
    }
    return nullptr;
}
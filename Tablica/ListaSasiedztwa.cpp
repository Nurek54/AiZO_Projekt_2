#include "ListaSasiedztwa.h"

ListaSasiedztwa::ListaSasiedztwa(size_t liczbaKrawedzi, size_t liczbaWierzcholkow, size_t* dane)
        : liczbaKrawedzi(liczbaKrawedzi), liczbaWierzcholkow(liczbaWierzcholkow) {
    krawedzie = new Krawedz* [liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; i++) {
        krawedzie[i] = nullptr;
    }

    Krawedz* krawedz = nullptr;
    size_t liczbaDanych = 3 * liczbaKrawedzi;
    size_t obecnyIndeks = 0;

    while (obecnyIndeks < liczbaDanych) {
        krawedz = krawedzie[dane[obecnyIndeks]];

        if (krawedz == nullptr) {
            krawedzie[dane[obecnyIndeks]] = new Krawedz{dane[obecnyIndeks], dane[obecnyIndeks + 1], dane[obecnyIndeks + 2], nullptr, nullptr};
            obecnyIndeks += 3;
            continue;
        }

        while (krawedz->nastepna != nullptr) {
            krawedz = krawedz->nastepna;
        }

        krawedz->nastepna = new Krawedz{dane[obecnyIndeks], dane[obecnyIndeks + 1], dane[obecnyIndeks + 2], nullptr, krawedz};
        obecnyIndeks += 3;
    }
}

ListaSasiedztwa::~ListaSasiedztwa() {
    if (krawedzie != nullptr) {
        Krawedz* krawedzDoUsuniecia = nullptr;

        for (size_t i = 0; i < liczbaWierzcholkow; i++) {
            krawedzDoUsuniecia = krawedzie[i];

            if (krawedzDoUsuniecia == nullptr) {
                continue;
            }

            while (krawedzDoUsuniecia->nastepna != nullptr) {
                krawedzDoUsuniecia = krawedzDoUsuniecia->nastepna;
                delete krawedzDoUsuniecia->poprzednia;
            }
            delete krawedzDoUsuniecia;
        }

        delete[] krawedzie;
    }
}

void ListaSasiedztwa::drukuj(std::ostream& wyjscie) const {
    Krawedz* krawedz = nullptr;

    for (size_t i = 0; i < liczbaWierzcholkow; i++) {
        wyjscie << std::setw(2) << i << " --> ";

        krawedz = krawedzie[i];

        if (krawedz == nullptr) {
            wyjscie << std::endl;
            continue;
        }

        while (krawedz != nullptr) {
            wyjscie << std::setw(2) << krawedz->koniec << '[' << std::setw(2) << krawedz->wartosc << "] | ";
            krawedz = krawedz->nastepna;
        }

        wyjscie << std::endl;
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

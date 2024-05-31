#include "KopiecKrawedzi.h"
#include <iostream>

using namespace std;

KopiecKrawedzi::KopiecKrawedzi(bool czyscPrzyUsuwaniu)
        : czyscPrzyUsuwaniu(czyscPrzyUsuwaniu), rozmiar(0), korzen(nullptr) {}

KopiecKrawedzi::~KopiecKrawedzi() {
    if (czyscPrzyUsuwaniu) {
        for (size_t i = 0; i < rozmiar; ++i) {
            delete korzen[i];
        }
    }
    delete[] korzen;
}

void KopiecKrawedzi::dodaj(Krawedz* krawedz) {
    Krawedz** bufor = new Krawedz*[rozmiar + 1];
    for (size_t i = 0; i < rozmiar; ++i) {
        bufor[i] = korzen[i];
    }
    bufor[rozmiar] = krawedz;
    delete[] korzen;
    korzen = bufor;
    ++rozmiar;
    naprawWGore();
}

Krawedz* KopiecKrawedzi::usun() {
    if (rozmiar == 0) {
        return nullptr;
    }

    Krawedz* krawedzDoZwrotu = korzen[0];
    korzen[0] = korzen[--rozmiar];

    Krawedz** bufor = new Krawedz*[rozmiar];
    for (size_t i = 0; i < rozmiar; ++i) {
        bufor[i] = korzen[i];
    }
    delete[] korzen;
    korzen = bufor;
    naprawWDol();
    return krawedzDoZwrotu;
}

bool KopiecKrawedzi::jestPusty() const {
    return rozmiar == 0;
}

void KopiecKrawedzi::drukuj() const {
    for (size_t i = 0; i < rozmiar; ++i) {
        cout << korzen[i]->poczatek << ' ' << korzen[i]->koniec << ' ' << korzen[i]->wartosc << endl;
    }
}

void KopiecKrawedzi::naprawWGore() {
    int i = rozmiar - 1;
    int rodzic = (i - 1) / 2;
    while (i > 0 && korzen[rodzic]->wartosc > korzen[i]->wartosc) {
        swap(korzen[i], korzen[rodzic]);
        i = rodzic;
        rodzic = (i - 1) / 2;
    }
}

void KopiecKrawedzi::naprawWDol() {
    int i = 0;
    while (2 * i + 1 < rozmiar) {
        int j = 2 * i + 1;
        if (j + 1 < rozmiar && korzen[j]->wartosc > korzen[j + 1]->wartosc) {
            j++;
        }
        if (korzen[i]->wartosc <= korzen[j]->wartosc) {
            break;
        }
        swap(korzen[i], korzen[j]);
        i = j;
    }
}
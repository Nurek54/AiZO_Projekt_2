#include "KopiecKrawedzi.h"
#include "ListaSasiedztwa.h"
#include <iostream>

KopiecKrawedzi::KopiecKrawedzi(bool czyscPrzyUsuwaniu) : czyscPrzyUsuwaniu(czyscPrzyUsuwaniu), rozmiar(0), korzen(nullptr) {}

KopiecKrawedzi::~KopiecKrawedzi() {
    if (rozmiar == 0) {
        return;
    }

    if (czyscPrzyUsuwaniu) {
        for (size_t i = 0; i < rozmiar; i++) {
            delete korzen[i];
        }
    }

    delete[] korzen;
}

void KopiecKrawedzi::dodaj(Krawedz* krawedz) {
    if (rozmiar == 0) {
        rozmiar++;
        korzen = new Krawedz * [rozmiar];
        korzen[0] = krawedz;
        return;
    }

    Krawedz** bufor = new Krawedz * [rozmiar + 1];
    for (size_t i = 0; i < rozmiar; i++) {
        bufor[i] = korzen[i];
    }

    delete[] korzen;
    korzen = bufor;
    korzen[rozmiar] = krawedz;
    rozmiar++;
    naprawWGore();
}

Krawedz* KopiecKrawedzi::usun() {
    if (rozmiar == 0) {
        return nullptr;
    }

    Krawedz* krawedzDoZwrotu = korzen[0];

    if (rozmiar == 1) {
        rozmiar--;
        delete[] korzen;
        korzen = nullptr;
        return krawedzDoZwrotu;
    }

    korzen[0] = korzen[rozmiar - 1];
    rozmiar--;

    Krawedz** bufor = new Krawedz * [rozmiar];
    for (size_t i = 0; i < rozmiar; i++) {
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
    for (size_t i = 0; i < rozmiar; i++) {
        std::cout << korzen[i]->poczatek << ' ' << korzen[i]->koniec << ' ' << korzen[i]->wartosc << std::endl;
    }
}

void KopiecKrawedzi::naprawWGore() {
    int i = rozmiar - 1;
    int rodzic = (i - 1) / 2;
    Krawedz* bufor = nullptr;

    while (korzen[rodzic]->wartosc > korzen[i]->wartosc) {
        bufor = korzen[rodzic];
        korzen[rodzic] = korzen[i];
        korzen[i] = bufor;
        i = rodzic;
        rodzic = (i - 1) / 2;
    }
}

void KopiecKrawedzi::naprawWDol() {
    int i = 0;
    int j = 2 * i + 1;
    Krawedz* bufor = nullptr;

    while (j < rozmiar) {
        if (j + 1 < rozmiar && korzen[j]->wartosc > korzen[j + 1]->wartosc) {
            j += 1;
        }

        if (korzen[i]->wartosc <= korzen[j]->wartosc) {
            break;
        }

        bufor = korzen[i];
        korzen[i] = korzen[j];
        korzen[j] = bufor;
        i = j;
        j = 2 * i + 1;
    }
}

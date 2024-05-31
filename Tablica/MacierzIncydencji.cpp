#include "MacierzIncydencji.h"

using namespace std;

MacierzIncydencji::MacierzIncydencji(size_t liczbaKrawedzi, size_t liczbaWierzcholkow, size_t* dane)
        : liczbaKrawedzi(liczbaKrawedzi), liczbaWierzcholkow(liczbaWierzcholkow) {
    wartosciKrawedzi = new size_t[liczbaKrawedzi];
    macierzHandler = new KomorkaMacierzy*[liczbaWierzcholkow];
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        macierzHandler[i] = new KomorkaMacierzy[liczbaKrawedzi];
        for (size_t j = 0; j < liczbaKrawedzi; ++j) {
            macierzHandler[i][j] = KomorkaMacierzy::Brak;
        }
    }

    size_t indeks = 0;
    for (size_t i = 0; i < liczbaKrawedzi; ++i) {
        size_t poczatek = dane[indeks++];
        size_t koniec = dane[indeks++];
        size_t wartosc = dane[indeks++];
        macierzHandler[poczatek][i] = KomorkaMacierzy::Poczatek;
        macierzHandler[koniec][i] = KomorkaMacierzy::Koniec;
        wartosciKrawedzi[i] = wartosc;
    }
}

MacierzIncydencji::~MacierzIncydencji() {
    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        delete[] macierzHandler[i];
    }
    delete[] macierzHandler;
    delete[] wartosciKrawedzi;
}

void MacierzIncydencji::drukuj(ostream& wyjscie) const {
    wyjscie << "    ";
    for (size_t i = 0; i < liczbaKrawedzi; ++i) {
        wyjscie << setw(2) << i << "   ";
    }
    wyjscie << endl;

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        wyjscie << setw(2) << i << "  ";
        for (size_t j = 0; j < liczbaKrawedzi; ++j) {
            wyjscie << setw(2) << static_cast<int>(macierzHandler[i][j]) << " | ";
        }
        wyjscie << endl;
    }

    wyjscie << " w  ";
    for (size_t i = 0; i < liczbaKrawedzi; ++i) {
        wyjscie << setw(2) << wartosciKrawedzi[i] << " | ";
    }
    wyjscie << endl;
}

size_t MacierzIncydencji::pobierzLiczbeWierzcholkow() const {
    return liczbaWierzcholkow;
}

size_t MacierzIncydencji::pobierzLiczbeKrawedzi() const {
    return liczbaKrawedzi;
}

KomorkaMacierzy** MacierzIncydencji::pobierzMacierz() const {
    return macierzHandler;
}

size_t* MacierzIncydencji::pobierzWartosci() const {
    return wartosciKrawedzi;
}

int MacierzIncydencji::pobierzWage(size_t u, size_t v) const {
    for (size_t i = 0; i < liczbaKrawedzi; ++i) {
        if (macierzHandler[u][i] == KomorkaMacierzy::Poczatek && macierzHandler[v][i] == KomorkaMacierzy::Koniec) {
            return wartosciKrawedzi[i];
        }
    }
    return -1; // Jeśli nie znaleziono krawędzi, zwróć -1
}
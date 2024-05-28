#include "MacierzIncydencji.h"

MacierzIncydencji::MacierzIncydencji(size_t liczbaKrawedzi, size_t liczbaWierzcholkow, size_t* dane)
        : liczbaKrawedzi(liczbaKrawedzi), liczbaWierzcholkow(liczbaWierzcholkow) {
    wartosciKrawedzi = new size_t[liczbaKrawedzi];
    macierzHandler = new KomorkaMacierzy* [liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; i++) {
        macierzHandler[i] = new KomorkaMacierzy[liczbaKrawedzi];
        for (size_t j = 0; j < liczbaKrawedzi; j++) {
            macierzHandler[i][j] = KomorkaMacierzy::Brak;
        }
    }

    int indeksDanych = 0;
    int indeksWartosci = 0;
    for (size_t i = 0; i < liczbaKrawedzi; i++) {
        auto wartosc = dane[indeksDanych];
        macierzHandler[dane[indeksDanych]][i] = KomorkaMacierzy::Poczatek;
        indeksDanych++;
        macierzHandler[dane[indeksDanych]][i] = KomorkaMacierzy::Koniec;
        indeksDanych++;
        wartosciKrawedzi[indeksWartosci] = dane[indeksDanych];
        indeksDanych++;
        indeksWartosci++;
    }
}

MacierzIncydencji::~MacierzIncydencji() {
    if (macierzHandler != nullptr) {
        for (size_t i = 0; i < liczbaWierzcholkow; i++) {
            delete[] macierzHandler[i];
        }
        delete[] macierzHandler;
    }
}

void MacierzIncydencji::drukuj(std::ostream& wyjscie) const {
    wyjscie << "    ";
    for (size_t i = 0; i < liczbaKrawedzi; i++) {
        wyjscie << std::setw(2) << i << "   ";
    }
    wyjscie << std::endl;

    for (size_t i = 0; i < liczbaWierzcholkow; i++) {
        wyjscie << std::setw(2) << i << "  ";
        for (size_t j = 0; j < liczbaKrawedzi; j++) {
            wyjscie << std::setw(2) << static_cast<int>(macierzHandler[i][j]) << " | ";
        }
        wyjscie << std::endl;
    }

    wyjscie << " w  ";
    for (size_t i = 0; i < liczbaKrawedzi; i++) {
        wyjscie << std::setw(2) << wartosciKrawedzi[i] << " | ";
    }
    wyjscie << std::endl;
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

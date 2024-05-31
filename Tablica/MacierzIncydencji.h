#ifndef MACIERZINCYDENCJI_H
#define MACIERZINCYDENCJI_H

#include <iostream>
#include <iomanip>

using namespace std;

enum class KomorkaMacierzy {
    Brak,
    Poczatek,
    Koniec
};

class MacierzIncydencji {
public:
    MacierzIncydencji(size_t liczbaKrawedzi, size_t liczbaWierzcholkow, size_t* dane);
    ~MacierzIncydencji();

    void drukuj(ostream& wyjscie) const;
    size_t pobierzLiczbeWierzcholkow() const;
    size_t pobierzLiczbeKrawedzi() const;
    KomorkaMacierzy** pobierzMacierz() const;
    size_t* pobierzWartosci() const;
    int pobierzWage(size_t u, size_t v) const;

private:
    size_t liczbaKrawedzi;
    size_t liczbaWierzcholkow;
    KomorkaMacierzy** macierzHandler;
    size_t* wartosciKrawedzi;
};

#endif // MACIERZINCYDENCJI_H
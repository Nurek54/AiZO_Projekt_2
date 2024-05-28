#ifndef TABLICA_H
#define TABLICA_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Tablica {
private:
    T* glowa;
    size_t rozmiar;

public:
    Tablica() : glowa(nullptr), rozmiar(0) {}
    Tablica(const Tablica<T>& tablica);
    ~Tablica();

    void dodajNaPoczatek(const T& dane);
    void dodajNaKoniec(const T& dane);
    bool dodajNaPozycje(const size_t& indeks, const T& dane);
    bool szukaj(const T& dane) const;
    bool usunZPoczatku();
    bool usunZKonca();
    bool usunZPozycji(const size_t& indeks);

    void drukuj(std::ostream& wyjscie) const;

    T getPoczatek() const;
    T getKoniec() const;
    T getNaPozycji(const size_t& indeks) const;

    size_t getRozmiar() const;
};

// Implementacja funkcji członkowskich

template <typename T>
Tablica<T>::Tablica(const Tablica<T>& tablica) {
    this->glowa = new T[tablica.rozmiar];
    for (size_t i = 0; i < tablica.rozmiar; i++) {
        this->glowa[i] = tablica.glowa[i];
    }
    this->rozmiar = tablica.rozmiar;
}

template <typename T>
Tablica<T>::~Tablica() {
    if (this->glowa != nullptr) {
        delete[] this->glowa;
    }
}

template <typename T>
void Tablica<T>::dodajNaPoczatek(const T& dane) {
    T* nowaGlowa = new T[this->rozmiar + 1];
    nowaGlowa[0] = dane;

    if (this->glowa != nullptr) {
        for (size_t i = 0; i < this->rozmiar; i++) {
            nowaGlowa[i + 1] = this->glowa[i];
        }
        delete[] this->glowa;
    }

    this->rozmiar++;
    this->glowa = nowaGlowa;
}

template <typename T>
void Tablica<T>::dodajNaKoniec(const T& dane) {
    T* nowaGlowa = new T[this->rozmiar + 1];
    nowaGlowa[this->rozmiar] = dane;

    if (this->glowa != nullptr) {
        for (size_t i = 0; i < this->rozmiar; i++) {
            nowaGlowa[i] = this->glowa[i];
        }
        delete[] this->glowa;
    }

    this->rozmiar++;
    this->glowa = nowaGlowa;
}

template <typename T>
bool Tablica<T>::dodajNaPozycje(const size_t& indeks, const T& dane) {
    if (indeks > this->rozmiar) {
        return false;
    }

    T* nowaGlowa = new T[this->rozmiar + 1];
    nowaGlowa[indeks] = dane;

    for (size_t i = 0; i < indeks; i++) {
        nowaGlowa[i] = this->glowa[i];
    }

    for (size_t i = indeks + 1; i <= rozmiar; i++) {
        nowaGlowa[i] = this->glowa[i - 1];
    }

    delete[] this->glowa;
    this->rozmiar++;
    this->glowa = nowaGlowa;
    return true;
}

template <typename T>
bool Tablica<T>::szukaj(const T& dane) const {
    if (this->rozmiar == 0) {
        return false;
    }

    for (size_t i = 0; i < this->rozmiar; i++) {
        if (this->glowa[i] == dane) {
            return true;
        }
    }

    return false;
}

template <typename T>
bool Tablica<T>::usunZPoczatku() {
    if (this->glowa == nullptr) {
        return false;
    }

    T* nowaGlowa = nullptr;

    if (this->rozmiar > 1) {
        nowaGlowa = new T[rozmiar - 1];
        for (size_t i = 1; i < this->rozmiar; i++) {
            nowaGlowa[i - 1] = this->glowa[i];
        }
    }

    delete[] this->glowa;
    this->rozmiar--;
    this->glowa = nowaGlowa;
    return true;
}

template <typename T>
bool Tablica<T>::usunZKonca() {
    if (this->glowa == nullptr) {
        return false;
    }

    T* nowaGlowa = nullptr;
    this->rozmiar--;

    if (this->rozmiar >= 1) {
        nowaGlowa = new T[rozmiar];
        for (size_t i = 0; i < this->rozmiar; i++) {
            nowaGlowa[i] = this->glowa[i];
        }
    }

    delete[] this->glowa;
    this->glowa = nowaGlowa;
    return true;
}

template <typename T>
bool Tablica<T>::usunZPozycji(const size_t& indeks) {
    if (indeks >= this->rozmiar) {
        return false;
    }

    T* nowaGlowa = nullptr;

    if (this->rozmiar > 1) {
        nowaGlowa = new T[rozmiar - 1];

        for (size_t i = 0; i < indeks; i++) {
            nowaGlowa[i] = this->glowa[i];
        }

        for (size_t i = indeks + 1; i < rozmiar; i++) {
            nowaGlowa[i - 1] = this->glowa[i];
        }
    }

    delete[] this->glowa;
    this->rozmiar--;
    this->glowa = nowaGlowa;
    return true;
}

template <typename T>
void Tablica<T>::drukuj(std::ostream& wyjscie) const {
    if (this->rozmiar > 0 && this->glowa != nullptr) {
        for (size_t i = 0; i < this->rozmiar; i++) {
            wyjscie << i << "> " << this->glowa[i] << std::endl;
        }
        return;
    }
    wyjscie << "Struktura danych jest pusta" << std::endl;
}

template <typename T>
T Tablica<T>::getPoczatek() const {
    if (this->rozmiar == 0) {
        throw std::runtime_error("Rozmiar jest 0");
    }

    return this->glowa[0];
}

template <typename T>
T Tablica<T>::getKoniec() const {
    if (this->rozmiar == 0) {
        throw std::runtime_error("Rozmiar jest 0");
    }

    return this->glowa[this->rozmiar - 1];
}

template <typename T>
T Tablica<T>::getNaPozycji(const size_t& indeks) const {
    if (indeks >= this->rozmiar) {
        throw std::runtime_error("Indeks poza zakresem");
    }

    return this->glowa[indeks];
}

template <typename T>
size_t Tablica<T>::getRozmiar() const {
    return this->rozmiar;
}

// Przeciążenie operatora << dla klasy KrawedzSciezki
class KrawedzSciezki;
std::ostream& operator<<(std::ostream& wyjscie, const KrawedzSciezki& krawedz);

#endif // TABLICA_H

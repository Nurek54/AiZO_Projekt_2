#ifndef GENERATOR_GRAFOW_H
#define GENERATOR_GRAFOW_H

#include <tuple>
#include <cstddef>  // Dodajemy cstddef, aby zdefiniować size_t
#include <random>

struct SuroweDaneGrafu {
    size_t* dane;
    size_t liczbaWierzcholkow;
    size_t liczbaKrawedzi;
};

class GeneratorGrafow {
public:
    static SuroweDaneGrafu generuj(float gestosc, size_t liczbaWierzcholkow, size_t maxWartosc);
};

#endif // GENERATOR_GRAFOW_H

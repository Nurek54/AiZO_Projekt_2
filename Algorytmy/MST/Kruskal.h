#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../../Tablica/ListaSasiedztwa.h"
#include "../../Tablica/MacierzIncydencji.h"
#include "../../Tablica/KopiecKrawedzi.h"

using namespace std;

class Kruskal {
public:
    void uruchomDlaListy(const ListaSasiedztwa& graf);
    void uruchomDlaMacierzy(const MacierzIncydencji& graf);
private:
    void selectionSort(Krawedz* krawedzie, size_t liczbaKrawedzi);
};

#endif // KRUSKAL_H

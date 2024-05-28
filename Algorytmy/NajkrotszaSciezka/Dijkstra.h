#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../../Tablica/ListaSasiedztwa.h"
#include "../../Tablica/MacierzIncydencji.h"

class Dijkstra {
public:
    static void uruchomDlaListy(const ListaSasiedztwa& graf, int start);
    static void uruchomDlaMacierzy(const MacierzIncydencji& graf, int start);
};

#endif // DIJKSTRA_H

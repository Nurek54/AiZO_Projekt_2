#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../../Tablica/ListaSasiedztwa.h"
#include "../../Tablica/MacierzIncydencji.h"
#include "../../Tablica/KopiecKrawedzi.h"

class Kruskal {
public:
    static void uruchomDlaListy(const ListaSasiedztwa& graf);
    static void uruchomDlaMacierzy(const MacierzIncydencji& graf);
};

#endif // KRUSKAL_H

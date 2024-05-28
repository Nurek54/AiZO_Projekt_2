#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "../../Tablica/ListaSasiedztwa.h"
#include "../../Tablica/MacierzIncydencji.h"

class BellmanFord {
public:
    static void uruchomDlaListy(const ListaSasiedztwa& graf, int start);
    static void uruchomDlaMacierzy(const MacierzIncydencji& graf, int start);
};

#endif // BELLMANFORD_H

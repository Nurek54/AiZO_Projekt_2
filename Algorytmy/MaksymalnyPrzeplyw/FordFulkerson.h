#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include "../../Tablica/ListaSasiedztwa.h"
#include "../../Tablica/MacierzIncydencji.h"

using namespace std;

class FordFulkerson {
public:
    static int uruchomDlaListy(const ListaSasiedztwa& graf, int start, int koniec);
    static int uruchomDlaMacierzy(const MacierzIncydencji& graf, int start, int koniec);
};

#endif // FORDFULKERSON_H

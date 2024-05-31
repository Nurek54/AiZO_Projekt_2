#ifndef PRIM_H
#define PRIM_H

#include "../../Tablica/ListaSasiedztwa.h"
#include "../../Tablica/MacierzIncydencji.h"

using namespace std;

class Prim {
public:
    static void uruchomDlaListy(const ListaSasiedztwa& graf);
    static void uruchomDlaMacierzy(const MacierzIncydencji& graf);
};

#endif // PRIM_H

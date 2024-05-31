#ifndef GRAFMANAGER_H
#define GRAFMANAGER_H

#include <iostream>
#include <string>
#include "../Tablica/MacierzIncydencji.h"
#include "../Tablica/ListaSasiedztwa.h"
#include "../Utils/GeneratorGrafow.h"
#include "../Utils/CzytnikGrafow.h"
#include "../Algorytmy/MST/Kruskal.h"
#include "../Algorytmy/MST/Prim.h"
#include "../Algorytmy/NajkrotszaSciezka/Dijkstra.h"
#include "../Algorytmy/NajkrotszaSciezka/BellmanFord.h"
#include "../Algorytmy/MaksymalnyPrzeplyw/FordFulkerson.h"

using namespace std;

class GrafManager {
private:
    MacierzIncydencji* macierzIncydencji;
    ListaSasiedztwa* listaSasiedztwa;
    GeneratorGrafow generatorGrafow;
    CzytnikGrafow czytnikGrafow;

public:
    GrafManager() : macierzIncydencji(nullptr), listaSasiedztwa(nullptr), czytnikGrafow("") {}
    ~GrafManager() {
        delete macierzIncydencji;
        delete listaSasiedztwa;
    }

    void wczytajDaneZPliku();
    void wygenerujGrafLosowo();
    void wyswietlGraf();
    void uruchomAlgorytmMST();
    void uruchomAlgorytmNajkrotszejSciezki();
    void uruchomAlgorytmMaksymalnegoPrzeplywu();
};

#endif // GRAFMANAGER_H

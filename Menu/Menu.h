#ifndef MENU_H
#define MENU_H

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

class Menu {
private:
    MacierzIncydencji* macierzIncydencji;
    ListaSasiedztwa* listaSasiedztwa;
    GeneratorGrafow generatorGrafow;
    CzytnikGrafow czytnikGrafow;

    void wczytajDaneZPliku();
    void wygenerujGrafLosowo();
    void wyswietlGraf();
    void uruchomAlgorytmMST();
    void uruchomAlgorytmNajkrotszejSciezki();
    void uruchomAlgorytmMaksymalnegoPrzeplywu();

public:
    Menu() : macierzIncydencji(nullptr), listaSasiedztwa(nullptr), czytnikGrafow("") {}

    void wyswietlMenuGlowne();
};

#endif // MENU_H

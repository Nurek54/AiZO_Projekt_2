#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "GrafManager.h"

using namespace std;

class Menu {
private:
    GrafManager grafManager;

    void wczytajDaneZPliku();
    void wygenerujGrafLosowo();
    void wyswietlGraf();
    void uruchomAlgorytmMST();
    void uruchomAlgorytmNajkrotszejSciezki();
    void uruchomAlgorytmMaksymalnegoPrzeplywu();

public:
    Menu() {}
    void wyswietlMenuGlowne();
};

#endif // MENU_H

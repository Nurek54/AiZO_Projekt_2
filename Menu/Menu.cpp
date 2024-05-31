#include "Menu.h"

using namespace std;

void Menu::wyswietlMenuGlowne() {
    int wybor;
    do {
        cout << "=====================" << endl;
        cout << "    MENU GLOWNE    " << endl;
        cout << "=====================" << endl;
        cout << "1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Wyswietl graf" << endl;
        cout << "4. Uruchom algorytm MST" << endl;
        cout << "5. Uruchom algorytm najkrotszej sciezki" << endl;
        cout << "6. Uruchom algorytm maksymalnego przeplywu" << endl;
        cout << "7. Wyjscie" << endl;
        cout << "=====================" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;
        cout << endl;

        switch (wybor) {
            case 1:
                wczytajDaneZPliku();
                break;
            case 2:
                wygenerujGrafLosowo();
                break;
            case 3:
                wyswietlGraf();
                break;
            case 4:
                uruchomAlgorytmMST();
                break;
            case 5:
                uruchomAlgorytmNajkrotszejSciezki();
                break;
            case 6:
                uruchomAlgorytmMaksymalnegoPrzeplywu();
                break;
            case 7:
                cout << "Koniec programu." << endl;
                break;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
        }
        cout << endl;
    } while (wybor != 7);
}

void Menu::wczytajDaneZPliku() {
    grafManager.wczytajDaneZPliku();
}

void Menu::wygenerujGrafLosowo() {
    grafManager.wygenerujGrafLosowo();
}

void Menu::wyswietlGraf() {
    grafManager.wyswietlGraf();
}

void Menu::uruchomAlgorytmMST() {
    grafManager.uruchomAlgorytmMST();
}

void Menu::uruchomAlgorytmNajkrotszejSciezki() {
    grafManager.uruchomAlgorytmNajkrotszejSciezki();
}

void Menu::uruchomAlgorytmMaksymalnegoPrzeplywu() {
    grafManager.uruchomAlgorytmMaksymalnegoPrzeplywu();
}
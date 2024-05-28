#include "Menu.h"

void Menu::wyswietlMenuGlowne() {
    int wybor;
    do {
        std::cout << "1. Wczytaj dane z pliku" << std::endl;
        std::cout << "2. Wygeneruj graf losowo" << std::endl;
        std::cout << "3. Wyswietl graf" << std::endl;
        std::cout << "4. Uruchom algorytm MST" << std::endl;
        std::cout << "5. Uruchom algorytm najkrotszej sciezki" << std::endl;
        std::cout << "6. Uruchom algorytm maksymalnego przeplywu" << std::endl;
        std::cout << "7. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

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
                std::cout << "Koniec programu." << std::endl;
                break;
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        }
    } while (wybor != 7);
}

void Menu::wczytajDaneZPliku() {
    std::string nazwaPliku;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> nazwaPliku;

    macierzIncydencji = czytnikGrafow.wczytajMacierz(nazwaPliku);
    listaSasiedztwa = czytnikGrafow.wczytajListe(nazwaPliku);

    if (macierzIncydencji && listaSasiedztwa) {
        std::cout << "Dane zostaly wczytane pomyslnie." << std::endl;
    } else {
        std::cout << "Blad wczytywania danych." << std::endl;
    }
}

void Menu::wygenerujGrafLosowo() {
    size_t liczbaWierzcholkow;
    float gestosc;
    size_t maxWartosc;

    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> liczbaWierzcholkow;
    std::cout << "Podaj gestosc grafu (w %): ";
    std::cin >> gestosc;
    std::cout << "Podaj maksymalna wartosc krawedzi: ";
    std::cin >> maxWartosc;

    SuroweDaneGrafu dane = generatorGrafow.generuj(gestosc / 100.0, liczbaWierzcholkow, maxWartosc);

    macierzIncydencji = new MacierzIncydencji(dane.liczbaKrawedzi, dane.liczbaWierzcholkow, dane.dane);
    listaSasiedztwa = new ListaSasiedztwa(dane.liczbaKrawedzi, dane.liczbaWierzcholkow, dane.dane);

    delete[] dane.dane;

    std::cout << "Graf zostal wygenerowany pomyslnie." << std::endl;
}

void Menu::wyswietlGraf() {
    if (macierzIncydencji) {
        std::cout << "Macierz Incydencji:" << std::endl;
        macierzIncydencji->drukuj(std::cout);
    }

    if (listaSasiedztwa) {
        std::cout << "Lista Sasiedztwa:" << std::endl;
        listaSasiedztwa->drukuj(std::cout);
    }
}

void Menu::uruchomAlgorytmMST() {
    if (!macierzIncydencji || !listaSasiedztwa) {
        std::cout << "Graf nie zostal wczytany ani wygenerowany." << std::endl;
        return;
    }

    int wybor;
    std::cout << "Wybierz algorytm MST:" << std::endl;
    std::cout << "1. Kruskal" << std::endl;
    std::cout << "2. Prim" << std::endl;
    std::cout << "Wybierz opcje: ";
    std::cin >> wybor;

    switch (wybor) {
        case 1: {
            Kruskal kruskal;
            std::cout << "Wybierz reprezentacje grafu:" << std::endl;
            std::cout << "1. Macierz Incydencji" << std::endl;
            std::cout << "2. Lista Sasiedztwa" << std::endl;
            std::cout << "Wybierz opcje: ";
            std::cin >> wybor;
            if (wybor == 1) {
                kruskal.uruchomDlaMacierzy(*macierzIncydencji);
            } else {
                kruskal.uruchomDlaListy(*listaSasiedztwa);
            }
            break;
        }
        case 2: {
            Prim prim;
            std::cout << "Wybierz reprezentacje grafu:" << std::endl;
            std::cout << "1. Macierz Incydencji" << std::endl;
            std::cout << "2. Lista Sasiedztwa" << std::endl;
            std::cout << "Wybierz opcje: ";
            std::cin >> wybor;
            if (wybor == 1) {
                prim.uruchomDlaMacierzy(*macierzIncydencji);
            } else {
                prim.uruchomDlaListy(*listaSasiedztwa);
            }
            break;
        }
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
    }
}

void Menu::uruchomAlgorytmNajkrotszejSciezki() {
    if (!macierzIncydencji || !listaSasiedztwa) {
        std::cout << "Graf nie zostal wczytany ani wygenerowany." << std::endl;
        return;
    }

    int wybor;
    int start, koniec;
    std::cout << "Podaj wierzcholek startowy: ";
    std::cin >> start;
    std::cout << "Podaj wierzcholek koncowy: ";
    std::cin >> koniec;

    std::cout << "Wybierz algorytm najkrotszej sciezki:" << std::endl;
    std::cout << "1. Dijkstra" << std::endl;
    std::cout << "2. Bellman-Ford" << std::endl;
    std::cout << "Wybierz opcje: ";
    std::cin >> wybor;

    switch (wybor) {
        case 1: {
            Dijkstra dijkstra;
            std::cout << "Wybierz reprezentacje grafu:" << std::endl;
            std::cout << "1. Macierz Incydencji" << std::endl;
            std::cout << "2. Lista Sasiedztwa" << std::endl;
            std::cout << "Wybierz opcje: ";
            std::cin >> wybor;
            if (wybor == 1) {
                dijkstra.uruchomDlaMacierzy(*macierzIncydencji, start);
            } else {
                dijkstra.uruchomDlaListy(*listaSasiedztwa, start);
            }
            break;
        }
        case 2: {
            BellmanFord bellmanFord;
            std::cout << "Wybierz reprezentacje grafu:" << std::endl;
            std::cout << "1. Macierz Incydencji" << std::endl;
            std::cout << "2. Lista Sasiedztwa" << std::endl;
            std::cout << "Wybierz opcje: ";
            std::cin >> wybor;
            if (wybor == 1) {
                bellmanFord.uruchomDlaMacierzy(*macierzIncydencji, start);
            } else {
                bellmanFord.uruchomDlaListy(*listaSasiedztwa, start);
            }
            break;
        }
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
    }
}

void Menu::uruchomAlgorytmMaksymalnegoPrzeplywu() {
    if (!macierzIncydencji || !listaSasiedztwa) {
        std::cout << "Graf nie zostal wczytany ani wygenerowany." << std::endl;
        return;
    }

    int start, koniec;
    std::cout << "Podaj wierzcholek startowy: ";
    std::cin >> start;
    std::cout << "Podaj wierzcholek koncowy: ";
    std::cin >> koniec;

    int wybor; // Dodana deklaracja zmiennej wybor
    FordFulkerson fordFulkerson;
    std::cout << "Wybierz reprezentacje grafu:" << std::endl;
    std::cout << "1. Macierz Incydencji" << std::endl;
    std::cout << "2. Lista Sasiedztwa" << std::endl;
    std::cout << "Wybierz opcje: ";
    std::cin >> wybor;

    int maxFlow;
    if (wybor == 1) {
        maxFlow = fordFulkerson.uruchomDlaMacierzy(*macierzIncydencji, start, koniec);
    } else {
        maxFlow = fordFulkerson.uruchomDlaListy(*listaSasiedztwa, start, koniec);
    }

    std::cout << "Maksymalny przeplyw wynosi: " << maxFlow << std::endl;
}

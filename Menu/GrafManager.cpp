#include "GrafManager.h"

void GrafManager::wczytajDaneZPliku() {
    string nazwaPliku;
    cout << "Podaj nazwe pliku: ";
    cin >> nazwaPliku;
    cout << endl;

    macierzIncydencji = czytnikGrafow.wczytajMacierz(nazwaPliku);
    listaSasiedztwa = czytnikGrafow.wczytajListe(nazwaPliku);

    if (macierzIncydencji && listaSasiedztwa) {
        cout << "Dane zostaly wczytane pomyslnie." << endl;
    } else {
        cout << "Blad wczytywania danych." << endl;
    }
    cout << endl;
}

void GrafManager::wygenerujGrafLosowo() {
    size_t liczbaWierzcholkow;
    float gestosc;
    size_t maxWartosc;

    cout << "Podaj liczbe wierzcholkow: ";
    cin >> liczbaWierzcholkow;
    cout << "Podaj gestosc grafu (w %): ";
    cin >> gestosc;
    cout << "Podaj maksymalna wartosc krawedzi: ";
    cin >> maxWartosc;
    cout << endl;

    SuroweDaneGrafu dane = generatorGrafow.generuj(gestosc / 100.0, liczbaWierzcholkow, maxWartosc);

    macierzIncydencji = new MacierzIncydencji(dane.liczbaKrawedzi, dane.liczbaWierzcholkow, dane.dane);
    listaSasiedztwa = new ListaSasiedztwa(dane.liczbaKrawedzi, dane.liczbaWierzcholkow, dane.dane);

    delete[] dane.dane;

    cout << "Graf zostal wygenerowany pomyslnie." << endl;
    cout << endl;
}

void GrafManager::wyswietlGraf() {
    if (macierzIncydencji) {
        cout << "Macierz Incydencji:" << endl;
        macierzIncydencji->drukuj(cout);
        cout << endl;
    }

    if (listaSasiedztwa) {
        cout << "Lista Sasiedztwa:" << endl;
        listaSasiedztwa->drukuj(cout);
        cout << endl;
    }
}

void GrafManager::uruchomAlgorytmMST() {
    if (!macierzIncydencji || !listaSasiedztwa) {
        cout << "Graf nie zostal wczytany ani wygenerowany." << endl;
        cout << endl;
        return;
    }

    int wybor;
    cout << "Wybierz algorytm MST:" << endl;
    cout << "1. Kruskal" << endl;
    cout << "2. Prim" << endl;
    cout << "Wybierz opcje: ";
    cin >> wybor;
    cout << endl;

    switch (wybor) {
        case 1: {
            Kruskal kruskal;
            cout << "Wybierz reprezentacje grafu:" << endl;
            cout << "1. Macierz Incydencji" << endl;
            cout << "2. Lista Sasiedztwa" << endl;
            cout << "Wybierz opcje: ";
            cin >> wybor;
            cout << endl;
            if (wybor == 1) {
                kruskal.uruchomDlaMacierzy(*macierzIncydencji);
            } else {
                kruskal.uruchomDlaListy(*listaSasiedztwa);
            }
            break;
        }
        case 2: {
            Prim prim;
            cout << "Wybierz reprezentacje grafu:" << endl;
            cout << "1. Macierz Incydencji" << endl;
            cout << "2. Lista Sasiedztwa" << endl;
            cout << "Wybierz opcje: ";
            cin >> wybor;
            cout << endl;
            if (wybor == 1) {
                prim.uruchomDlaMacierzy(*macierzIncydencji);
            } else {
                prim.uruchomDlaListy(*listaSasiedztwa);
            }
            break;
        }
        default:
            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
            cout << endl;
    }
}

void GrafManager::uruchomAlgorytmNajkrotszejSciezki() {
    if (!macierzIncydencji || !listaSasiedztwa) {
        cout << "Graf nie zostal wczytany ani wygenerowany." << endl;
        cout << endl;
        return;
    }

    int wybor;
    int start, koniec;
    cout << "Podaj wierzcholek startowy: ";
    cin >> start;
    cout << "Podaj wierzcholek koncowy: ";
    cin >> koniec;
    cout << endl;

    cout << "Wybierz algorytm najkrotszej sciezki:" << endl;
    cout << "1. Dijkstra" << endl;
    cout << "2. Bellman-Ford" << endl;
    cout << "Wybierz opcje: ";
    cin >> wybor;
    cout << endl;

    switch (wybor) {
        case 1: {
            Dijkstra dijkstra;
            cout << "Wybierz reprezentacje grafu:" << endl;
            cout << "1. Macierz Incydencji" << endl;
            cout << "2. Lista Sasiedztwa" << endl;
            cout << "Wybierz opcje: ";
            cin >> wybor;
            cout << endl;
            if (wybor == 1) {
                dijkstra.uruchomDlaMacierzy(*macierzIncydencji, start);
            } else {
                dijkstra.uruchomDlaListy(*listaSasiedztwa, start);
            }
            break;
        }
        case 2: {
            BellmanFord bellmanFord;
            cout << "Wybierz reprezentacje grafu:" << endl;
            cout << "1. Macierz Incydencji" << endl;
            cout << "2. Lista Sasiedztwa" << endl;
            cout << "Wybierz opcje: ";
            cin >> wybor;
            cout << endl;
            if (wybor == 1) {
                bellmanFord.uruchomDlaMacierzy(*macierzIncydencji, start);
            } else {
                bellmanFord.uruchomDlaListy(*listaSasiedztwa, start);
            }
            break;
        }
        default:
            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
            cout << endl;
    }
}

void GrafManager::uruchomAlgorytmMaksymalnegoPrzeplywu() {
    if (!macierzIncydencji || !listaSasiedztwa) {
        cout << "Graf nie zostal wczytany ani wygenerowany." << endl;
        cout << endl;
        return;
    }

    int start, koniec;
    cout << "Podaj wierzcholek startowy: ";
    cin >> start;
    cout << "Podaj wierzcholek koncowy: ";
    cin >> koniec;
    cout << endl;

    int wybor;
    FordFulkerson fordFulkerson;
    cout << "Wybierz reprezentacje grafu:" << endl;
    cout << "1. Macierz Incydencji" << endl;
    cout << "2. Lista Sasiedztwa" << endl;
    cout << "Wybierz opcje: ";
    cin >> wybor;
    cout << endl;

    int maxFlow;
    if (wybor == 1) {
        maxFlow = fordFulkerson.uruchomDlaMacierzy(*macierzIncydencji, start, koniec);
    } else {
        maxFlow = fordFulkerson.uruchomDlaListy(*listaSasiedztwa, start, koniec);
    }

    cout << "Maksymalny przeplyw wynosi: " << maxFlow << endl;
    cout << endl;
}
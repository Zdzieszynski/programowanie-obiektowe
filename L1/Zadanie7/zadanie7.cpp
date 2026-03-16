/*
Zadanie 7.Napisz program, który zadeklaruje trzy tablice tabA[4][4], tabB[4][4] i tabC[4][4]. Do tabA wpisze następnie cyfry:1 0 0 01 1 0 01 1 1 01 1 1 1Do tablicy tabB wpisz następujące cyfry:0 1 0 11 0 1 00 1 0 11 0 1 0Do tablicy tabC zapisz sumę tablicy tabA i tabB. Wypisz na ekran wszystkie trzy tablice.
*/

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 4;
    int tabA[SIZE][SIZE] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };
    
    int tabB[SIZE][SIZE] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    
    int tabC[SIZE][SIZE];

    // Obliczenie sumy tablic tabA i tabB
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabC[i][j] = tabA[i][j] + tabB[i][j];
        }
    }

    // Wypisanie tablicy tabA
    cout << "Tablica A:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << tabA[i][j] << " ";
        }
        cout << endl;
    }

    // Wypisanie tablicy tabB
    cout << "Tablica B:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << tabB[i][j] << " ";
        }
        cout << endl;
    }

    // Wypisanie tablicy tabC
    cout << "Tablica C:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << tabC[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
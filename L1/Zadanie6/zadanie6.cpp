/* 
Zadanie 6.Napisz program, który zadeklaruje dwie tablice tabA[4][4] i tabB[4][4]. Do tabA wygeneruj następnie cyfry:2 2 2 24 4 4 46 6 6 68 8 8 8Za pomocą pętli, przepisz do tabB cyfry z tablicy tabA tak aby tabB była uzupełniona w ten sposób:2 4 6 82 4 6 82 4 6 82 4 6 8Wypisz na ekran obie tablice.
*/

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 4;
    int tabA[SIZE][SIZE] = {
        {2, 2, 2, 2},
        {4, 4, 4, 4},
        {6, 6, 6, 6},
        {8, 8, 8, 8}
    };
    
    int tabB[SIZE][SIZE];

    // Przepisanie wartości z tabA do tabB
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabB[i][j] = tabA[i][j] + (i + j) * 2; // Dodajemy (i+j)*2 do każdej wartości
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

    return 0;
}
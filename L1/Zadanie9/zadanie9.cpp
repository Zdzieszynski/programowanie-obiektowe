/* 
Zadanie 9
Utwórz plik o nazwie zad1.txt i wpisz do niego ręcznie przez notatnik takie cyfry:1 0 0 01 1 0 01 1 1 01 1 1 1Następnie utwórz plik o nazwie zad2.txt i wpisz do niego takie cyfry:0 0 0 03 3 3 30 0 0 03 3 3 3Następnie zapisz sumę tych macierzy do pliku wynik.txt
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int SIZE = 4;
    int tabA[SIZE][SIZE];
    int tabB[SIZE][SIZE];
    int tabC[SIZE][SIZE];

    // Wczytanie danych z pliku zad1.txt do tablicy tabA
    ifstream fileA("zad1.txt");
    if (fileA.is_open()) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                fileA >> tabA[i][j];
            }
        }
        fileA.close();
    } else {
        cout << "Nie można otworzyć pliku zad1.txt" << endl;
        return 1;
    }

    // Wczytanie danych z pliku zad2.txt do tablicy tabB
    ifstream fileB("zad2.txt");
    if (fileB.is_open()) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                fileB >> tabB[i][j];
            }
        }
        fileB.close();
    } else {
        cout << "Nie można otworzyć pliku zad2.txt" << endl;
        return 1;
    }

    // Obliczenie sumy tablic tabA i tabB do tablicy tabC
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabC[i][j] = tabA[i][j] + tabB[i][j];
        }
    }

    // Zapisanie wyniku do pliku wynik.txt
    ofstream resultFile("wynik.txt");
    if (resultFile.is_open()) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                resultFile << tabC[i][j] << " ";
            }
            resultFile << endl;
        }
        resultFile.close();
    } else {
        cout << "Nie można otworzyć pliku wynik.txt" << endl;
        return 1;
    }

    return 0;
}
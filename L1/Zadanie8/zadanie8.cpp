/*
Zadanie 8.Napisz program, który wypisze ilość wystąpień cyfr od 0 do 100 na ekran w ten sposób:‘0’ -> 2‘1’ -> 0zera są dwa, jedynka występuje zero razy, itp.plik z danymi który trzeba wczytać należy samemu utworzyć i wpisać 40 cyfr z zakresu od 0 do 100. Plik ma się nazywać „dane.txt”
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

    cout << "Suma macierzy została zapisana w pliku wynik.txt" << endl;
    return 0;
}
/*
Zadanie 11.Napisz funkcję która zwraca największą liczbę w tabeli. Definicja funkcji to: int max_tab(int t[], int n), funkcja pobiera tablicę oraz ilość elementów, a zwraca największy element. Tablica musi być zadeklarowana w main oraz ma takie wartości wpisane przy tworzeniu: 2,4,10,1,1,2,4,5,1,3
*/

#include <iostream>
using namespace std;

int max_tab(int t[], int n) {
    int max = t[0]; // Zakładamy, że pierwszy element jest największy
    for (int i = 1; i < n; i++) {
        if (t[i] > max) {
            max = t[i]; // Aktualizujemy max, jeśli znajdziemy większy element
        }
    }
    return max; // Zwracamy największy element
}

int main() {
    int tab[] = {2, 4, 10, 1, 1, 2, 4, 5, 1, 3};
    int n = sizeof(tab) / sizeof(tab[0]);
    cout << "Największa liczba w tabeli: " << max_tab(tab, n) << endl;
    return 0;
}
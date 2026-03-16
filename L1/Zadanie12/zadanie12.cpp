/*
Zadanie 12.Napisz funkcję która liczy silnię. Wszystkie zmienne w programie main są zmiennymi dynamicznymi (new). Pobierz od użytkownika jedną cyfrę a następnie przekaż ją do funkcji za pomocą wskaźnika. Funkcja zwraca wynik do programu za pomocą wskaźnika (w funkcji utwórz zmienną dynamiczną i zwróć ją do funkcji main). Deklaracja funkcji wygląda tak:int *silnia(int *a).
*/

#include <iostream>
using namespace std;

int *silnia(int *a) {
    int *result = new int(1); // Dynamiczna zmienna do przechowywania wyniku
    for (int i = 1; i <= *a; i++) {
        *result *= i; // Mnożymy wynik przez kolejne liczby od 1 do a
    }
    return result; // Zwracamy wskaźnik do wyniku
}

int main() {
    int *number = new int; // Dynamiczna zmienna do przechowywania liczby
    cout << "Podaj cyfrę: ";
    cin >> *number; // Wczytujemy wartość do dynamicznej zmiennej

    int *factorial = silnia(number); // Wywołujemy funkcję silnia i otrzymujemy wskaźnik do wyniku
    cout << "Silnia z " << *number << " to: " << *factorial << endl;

    // Zwolnienie pamięci dynamicznej
    delete number;
    delete factorial;

    return 0;
}

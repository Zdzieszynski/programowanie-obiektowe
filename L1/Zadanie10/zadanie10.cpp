/*
Zadanie 10.Napisz program który pobierze dwie cyfry od użytkownika a następnie przekaże je do funkcji. Funkcja ma za zadanie pomnożyć je i wynik przekazać do funkcji main. Deklaracja funkcji wygląda tak: int mnozenie(int &x, int &y)
*/

#include <iostream>
using namespace std;

int mnozenie(int &x, int &y) {
    return x * y;
}

int main() {
    int a, b;
    cout << "Podaj dwie cyfry: ";
    cin >> a >> b;
    cout << "Iloczyn: " << mnozenie(a, b) << endl;
    return 0;
}
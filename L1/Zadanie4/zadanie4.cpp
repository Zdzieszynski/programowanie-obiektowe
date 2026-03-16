/* Zadanie 4.Napisz program który prosi użytkownika o podanie cyfry.
 Następnie wyświetla tyle cyfr w wierszu oraz tyle
  samo kolumnie. Macierz musi być wypełniona szachownicą
   (przykład dla liczby 4)
   0,1,0,1,
   1,0,1,0,
   0,1,0,1,
   1,0,1,0,
   */
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj liczbę: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                cout << "0";
            } else {
                cout << "1";
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
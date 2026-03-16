/*
Zadanie 14.Program ma taką strukturę:typedef struct {int wysokosc;int szerokosc;}prostokat;Napisz program, który stworzy zmienną dynamiczną wedługstruktury „prostokat”, następnie wczyta zklawiatury dane. Następnie rysuje prostokąt z gwiazdek o podanej szerokości i wysokości oraz liczy obwód oraz pole.   
*/
#include <iostream>
using namespace std;

typedef struct {
    int wysokosc;
    int szerokosc;
} prostokat;

int main() {
    prostokat *p = new prostokat;
    cout << "Podaj wysokość prostokąta: ";
    cin >> p->wysokosc;
    cout << "Podaj szerokość prostokąta: ";
    cin >> p->szerokosc;

    // Rysowanie prostokąta z gwiazdek
    for (int i = 0; i < p->wysokosc; i++) {
        for (int j = 0; j < p->szerokosc; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Liczenie obwodu i pola
    int obwod = 2 * (p->wysokosc + p->szerokosc);
    int pole = p->wysokosc * p->szerokosc;

    cout << "Obwód prostokąta: " << obwod << endl;
    cout << "Pole prostokąta: " << pole << endl;

    delete p;
    return 0;
}
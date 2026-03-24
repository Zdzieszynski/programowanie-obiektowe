/*
Zadanie 1.Napisz program który liczy cenę brutto. Podana jest klasa „koszt”
którą należy uzupełnić obrakujące elementy. Klasa ma mieć tylko jeden
konstruktor z dwoma argumentami (zmienne cena i podatek), przy czym zmienna
podatek ma mieć domyślny argument 23. Następnie musimy mieć destruktor który w
tym wypadku jest pusty oraz metodę „brutto” która nic nie pobiera a zwraca typ
double. Klasa: koszt class koszt{private:double cena;int
podatek;public://uzupelnic};Gdy już mamy uzupełnioną klasę spróbujmy sprawdzić
działanie jej w funkcji main:int main(int argc, char** argv) {double cen; int
pod; //wywołanie konstruktora cout<<"Podaj cene towaru: ";cin>>cen;cout<<"Podaj
stawke podatku: ";cin>>pod;koszt towar(cen, pod);cout<<"Cena brutto:
"<<towar.brutto()<<endl;//wywołanie konstruktora z domyslnym
argumentemcout<<"Podaj cene towaru: ";cin>>cen;koszt ksiazka(cen);cout<<"Cena
brutto: "<<ksiazka.brutto()<<endl;return 0;}Przetestuj program czy poprawnie
działa.
*/

#include <iostream>
using namespace std;

class koszt {
private:
    double cena;
    int podatek;
public:
    koszt(double c, int p = 23);
    ~koszt();
    double brutto();
};

koszt::koszt(double c, int p) : cena(c), podatek(p) {}

koszt::~koszt() {}

double koszt::brutto() {
    return cena + (cena * podatek / 100.0);
    
}


int main(int argc, char** argv) {
    double cen;
    int pod;

    cout << "Podaj cene towaru: ";
    cin >> cen;
    cout << "Podaj stawke podatku: ";
    cin >> pod;

    koszt towar(cen, pod);
    cout << "Cena brutto: " << towar.brutto() << endl;

    cout << "Podaj cene towaru: ";
    cin >> cen;

    koszt ksiazka(cen);
    cout << "Cena brutto: " << ksiazka.brutto() << endl;

    return 0;
}




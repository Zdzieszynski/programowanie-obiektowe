/*
Zadanie 13.Program ma taką strukturę:typedef struct {int re;//część rzeczywistaint im;//część urojona}zespolona;
31.Napisz program, który stworzy dwie zmienne według struktury „zespolona”. Następnie program musi poprosić o wpisanie do liczby pierwszej (cyfry do części rzeczywistej oraz cyfry do części urojonej). To samo trzeba zrobić z drugą liczbą. Następnie dodaj obieliczby zespolone. Dodawanie polega na dodaniu części rzeczywistej do części rzeczywistej, a części urojonej do urojonej. Po czym wypisz wynik według przykładu:  3+4i  gdzie w tym przykładzie 3 to część rzeczywista, a 4 to część urojona.
*/

#include <iostream>
using namespace std;

typedef struct {
    int re; // część rzeczywista
    int im; // część urojona
} zespolona;

int main() {
    zespolona z1, z2, wynik;

    cout << "Podaj część rzeczywistą pierwszej liczby zespolonej: ";
    cin >> z1.re;
    cout << "Podaj część urojoną pierwszej liczby zespolonej: ";
    cin >> z1.im;

    cout << "Podaj część rzeczywistą drugiej liczby zespolonej: ";
    cin >> z2.re;
    cout << "Podaj część urojoną drugiej liczby zespolonej: ";
    cin >> z2.im;

    // Dodawanie liczb zespolonych
    wynik.re = z1.re + z2.re; // Dodajemy części rzeczywiste
    wynik.im = z1.im + z2.im; // Dodajemy części urojone

    // Wyświetlenie wyniku
    cout << "Wynik dodawania: " << wynik.re << "+" << wynik.im << "i" << endl;

    return 0;
}
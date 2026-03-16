/*Zadanie 1. Napisz program kalkulator, gdzie mamy taką klasę:
class kalkulator {
private:
int liczba1;
int liczba2;
public:
kalkulator(void);
~kalkulator(void);
int dodawanie(void);
int odejmowanie(void);
int mnozenie(void);
void klawiatura(void);
};
Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Metoda klawiatura ma za zadanie pobrać z klawiatury dwie cyfry potrzebne do wykonania obliczeń. W funkcji main wywołaj wszystkie metody.
*/

#include <iostream>
using namespace std;

class kalkulator {
private:
    int liczba1;
    int liczba2;

public:
    kalkulator(void);      // konstruktor
    ~kalkulator(void);     // destruktor
    int dodawanie(void);
    int odejmowanie(void);
    int mnozenie(void);
    void klawiatura(void);
};

// ===== definicje metod =====

kalkulator::kalkulator(void) {
    liczba1 = 0;
    liczba2 = 0;
    cout << "Konstruktor uruchomiony" << endl;
}

kalkulator::~kalkulator(void) {
    cout << "Destruktor uruchomiony" << endl;
}

void kalkulator::klawiatura(void) {
    cout << "Podaj pierwsza liczbe: ";
    cin >> liczba1;

    cout << "Podaj druga liczbe: ";
    cin >> liczba2;
}

int kalkulator::dodawanie(void) {
    return liczba1 + liczba2;
}

int kalkulator::odejmowanie(void) {
    return liczba1 - liczba2;
}

int kalkulator::mnozenie(void) {
    return liczba1 * liczba2;
}

// ===== funkcja main =====

int main() {

    kalkulator k;

    k.klawiatura();

    cout << "Dodawanie: " << k.dodawanie() << endl;
    cout << "Odejmowanie: " << k.odejmowanie() << endl;
    cout << "Mnozenie: " << k.mnozenie() << endl;

    return 0;
}


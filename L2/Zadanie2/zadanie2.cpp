#include <iostream>
using namespace std;

class operacje {
private:
    int liczba1;
    int liczba2;

public:
    operacje(void);
    ~operacje(void);
    int wieksza(void);
    int mniejsza(void);
    int czy_rowne(void);
    void klawiatura(void);
};

operacje::operacje(void) {
    liczba1 = 0;
    liczba2 = 0;
}

operacje::~operacje(void) {
}

void operacje::klawiatura(void) {
    cout << "Podaj pierwsza liczbe: ";
    cin >> liczba1;
    cout << "Podaj druga liczbe: ";
    cin >> liczba2;
}

int operacje::wieksza(void) {
    if (liczba1 > liczba2)
        return liczba1;
    else
        return liczba2;
}

int operacje::mniejsza(void) {
    if (liczba1 < liczba2)
        return liczba1;
    else
        return liczba2;
}

int operacje::czy_rowne(void) {
    if (liczba1 == liczba2)
        return 1;
    else
        return 0;
}

int main() {

    operacje zadanie;

    zadanie.klawiatura();

    cout << "Wieksza liczba: " << zadanie.wieksza() << endl;
    cout << "Mniejsza liczba: " << zadanie.mniejsza() << endl;

    if(zadanie.czy_rowne())
    {
        cout<<" liczby sa rowne";
    }
    else
    {
        cout<<" liczby sa rozne";
    }

    return 0;
}
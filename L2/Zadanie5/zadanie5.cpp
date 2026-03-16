#include <iostream>
using namespace std;

class prostokat {
private:
    int bok1;
    int bok2;

public:
    prostokat(void);
    ~prostokat(void);
    int obwod(void);
    int pole(void);
    int czy_kwadrat(void);
    void klawiatura(void);
};

prostokat::prostokat(void) {
    bok1 = 0;
    bok2 = 0;
}

prostokat::~prostokat(void) {
}

void prostokat::klawiatura(void) {
    cout << "Podaj bok1: ";
    cin >> bok1;
    cout << "Podaj bok2: ";
    cin >> bok2;
}

int prostokat::obwod(void) {
    return 2 * (bok1 + bok2);
}

int prostokat::pole(void) {
    return bok1 * bok2;
}

int prostokat::czy_kwadrat(void) {
    if (bok1 == bok2)
        return 1;
    else
        return 0;
}

int main() {

    prostokat zadanie;

    zadanie.klawiatura();

    cout << "Obwod: " << zadanie.obwod() << endl;
    cout << "Pole: " << zadanie.pole() << endl;

    if (zadanie.czy_kwadrat())
        cout << "To jest kwadrat" << endl;
    else
        cout << "To nie jest kwadrat" << endl;

    return 0;
}
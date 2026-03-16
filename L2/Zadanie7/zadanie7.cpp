#include <iostream>
using namespace std;

class pojemnosc {
private:
    int podstawa1;
    int podstawa2;
    int wysokosc;

public:
    pojemnosc() {
        podstawa1 = 0;
        podstawa2 = 0;
        wysokosc = 0;
    }

    ~pojemnosc() {}

    void klawiatura() {
        cout << "Podaj podstawe1: ";
        cin >> podstawa1;
        cout << "Podaj podstawe2: ";
        cin >> podstawa2;
        cout << "Podaj wysokosc: ";
        cin >> wysokosc;
    }

    int prostopadloscian() {
        return podstawa1 * podstawa2 * wysokosc;
    }
};

int main() {

    pojemnosc *pr = new pojemnosc;

    pr->klawiatura();

    cout << "Objetosc prostopadloscianu: " << pr->prostopadloscian() << endl;

    delete pr;

    return 0;
}
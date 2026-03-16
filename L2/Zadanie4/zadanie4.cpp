#include <iostream>
using namespace std;

class trojkat {
private:
    int podstawa;
    int bok1;
    int bok2;
    int wysokosc;

public:
    trojkat(void);
    ~trojkat(void);
    int obwod(void);
    double pole(void);
    int pitagoras(void);
    int czy_rownoboczny(void);
    int czy_rownoramienny(void);
    void klawiatura(void);
};

trojkat::trojkat(void) {
    podstawa = 0;
    bok1 = 0;
    bok2 = 0;
    wysokosc = 0;
}

trojkat::~trojkat(void) {
}

void trojkat::klawiatura(void) {
    cout<<"Podaj podstawe: ";
    cin>>podstawa;
    cout<<"Podaj bok1: ";
    cin>>bok1;
    cout<<"Podaj bok2: ";
    cin>>bok2;
    cout<<"Podaj wysokosc: ";
    cin>>wysokosc;
}

int trojkat::obwod(void) {
    return podstawa + bok1 + bok2;
}

double trojkat::pole(void) {
    return (podstawa * wysokosc) / 2.0;
}

int trojkat::pitagoras(void) {
    if(podstawa*podstawa + bok1*bok1 == bok2*bok2 ||
       podstawa*podstawa + bok2*bok2 == bok1*bok1 ||
       bok1*bok1 + bok2*bok2 == podstawa*podstawa)
        return 1;
    else
        return 0;
}

int trojkat::czy_rownoboczny(void) {
    if(podstawa==bok1 && bok1==bok2)
        return 1;
    else
        return 0;
}

int trojkat::czy_rownoramienny(void) {
    if(podstawa==bok1 || podstawa==bok2 || bok1==bok2)
        return 1;
    else
        return 0;
}

int main() {

    trojkat zadanie;

    zadanie.klawiatura();

    cout<<"Obwod: "<<zadanie.obwod()<<endl;
    cout<<"Pole: "<<zadanie.pole()<<endl;

    if(zadanie.pitagoras())
        cout<<"Trojkat prostokatny"<<endl;
    else
        cout<<"Trojkat nie jest prostokatny"<<endl;

    if(zadanie.czy_rownoboczny())
        cout<<"Trojkat rownoboczny"<<endl;
    else
        cout<<"Trojkat nie jest rownoboczny"<<endl;

    if(zadanie.czy_rownoramienny())
        cout<<"Trojkat rownoramienny"<<endl;
    else
        cout<<"Trojkat nie jest rownoramienny"<<endl;

    return 0;
}
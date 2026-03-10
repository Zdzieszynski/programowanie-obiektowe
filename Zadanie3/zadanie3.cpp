#include <iostream>
using namespace std;

class algorytmy {
private:
    int liczba1;
    int liczba2;
    int liczba3;
    int liczba4;

public:
    algorytmy(void);
    ~algorytmy(void);
    int max(void);
    int mini(void);
    int suma(void);
    int szukana(int x);
    int parzyste(void);
    void klawiatura(void);
};

algorytmy::algorytmy(void) {
    liczba1 = 0;
    liczba2 = 0;
    liczba3 = 0;
    liczba4 = 0;
}

algorytmy::~algorytmy(void) {
}

void algorytmy::klawiatura(void) {
    cout<<"Podaj liczbe 1: ";
    cin>>liczba1;
    cout<<"Podaj liczbe 2: ";
    cin>>liczba2;
    cout<<"Podaj liczbe 3: ";
    cin>>liczba3;
    cout<<"Podaj liczbe 4: ";
    cin>>liczba4;
}

int algorytmy::max(void) {
    int m = liczba1;
    if(liczba2 > m) m = liczba2;
    if(liczba3 > m) m = liczba3;
    if(liczba4 > m) m = liczba4;
    return m;
}

int algorytmy::mini(void) {
    int m = liczba1;
    if(liczba2 < m) m = liczba2;
    if(liczba3 < m) m = liczba3;
    if(liczba4 < m) m = liczba4;
    return m;
}

int algorytmy::suma(void) {
    return liczba1 + liczba2 + liczba3 + liczba4;
}

int algorytmy::szukana(int x) {
    if(liczba1==x || liczba2==x || liczba3==x || liczba4==x)
        return 1;
    else
        return 0;
}

int algorytmy::parzyste(void) {
    if(liczba1%2==0 || liczba2%2==0 || liczba3%2==0 || liczba4%2==0)
        return 1;
    else
        return 0;
}

int main() {

    algorytmy zadanie;
    int x;

    zadanie.klawiatura();

    cout<<"Max: "<<zadanie.max()<<endl;
    cout<<"Min: "<<zadanie.mini()<<endl;
    cout<<"Suma: "<<zadanie.suma()<<endl;

    cout<<"Podaj liczbe do sprawdzenia: ";
    cin>>x;

    if(zadanie.szukana(x))
    {
        cout<<"liczba znaleziona"<<endl;
    }
    else
    {
        cout<<"liczby nie ma"<<endl;
    }

    if(zadanie.parzyste())
    {
        cout<<"jest liczba parzysta"<<endl;
    }
    else
    {
        cout<<"brak liczby parzystej"<<endl;
    }

    return 0;
}
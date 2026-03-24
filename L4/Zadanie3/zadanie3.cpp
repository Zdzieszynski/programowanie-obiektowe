/*
Zadanie 3.Program ma za zadanie wyliczenie kosztu zużycia paliwa. W metodzie
„wylicz” należy użyć takiego wzoru: „(zuzycie/100)*cena”. Poniżej jest podana
klasa koszt. Uzupełnij jej metody aby program działał. W tej klasie widzimy dwa
konstruktory. Pierwszy jest domyślny a drugi jest parametrowy. Gdy popatrzymy na
pierwszy konstruktor widzimy po dwukropku wywołanie konstruktora parametrowego z
dwoma parametrami (w tym wypadku 0 i 0). Taki zapis nazwany jest „delegowaniem
konstruktora”. Gdy w funkcji mainużyjemy konstruktora bez parametrowego program
wywoła konstruktor parametrowy z wpisanymi wartościami (w tym wypadku 0 i 0).Kod
klasy „koszt”:class koszt{private:double zuzycie;double
cena;public://konstruktor 1 domyslnykoszt(): koszt(0.0,0.0) {}//konstruktor 2
parametrowykoszt(double x, double y): zuzycie(x), cena(y) {}~koszt(void){}void
set_zuzycie(double x);void set_cena(double x);double get_zuzycie(void);double
get_cena(void);double wylicz(void);};Uzupełnij metody o ciało. Programowanie
obiektowe–L44Akademia Nauk Stosowanychw Nowym Sączu2025/ 2026r. ver. 1.0mgr inż.
Dawid KotlarskiFunkcja main:int main(int argc, char** argv) {double z;double
c;cout<<"Policzmy koszt jednego kilometra dla Opel: "<<endl;cout<<"Podaj zuzycie
paliwa: ";cin>>z;cout<<"Podaj cene paliwa: ";cin>>c;koszt opel;//konstruktor
domyslnycout<<"Koszt: "<<opel.wylicz()<<" zl.za
km"<<endl;//(1)opel.set_zuzycie(z);opel.set_cena(c);cout<<"jeszcze raz koszt:
"<<opel.wylicz()<<" zl.za km"<<endl<<endl;//(2)cout<<"Policzmy koszt jednego
kilometra dla VW: "<<endl;cout<<"Podaj zuzycie paliwa: ";cin>>z;cout<<"Podaj
cene paliwa: ";cin>>c;koszt vw(z,c);//konstruktor parametrowycout<<"Koszt:
"<<vw.wylicz()<<" zl.za km"<<endl;return 0;}Utworzyliśmy dwa obiekty. Pierwszy
to opel a drugi to vw. Zobacz że w linijce „koszt opel;” zostaje wywołany
konstruktor bezparametrowy,a w deklaracji klasy tam mamy delegowanie
konstruktora. Czyli wywołanie konstruktora parametrowego z zerami. W linijce
która ma w komentarzu (1) wyświetli nam 0 (wartości domyślne). W linijce gdzie w
komentarzu mamy (2) widzimy już wyliczony koszt. W obiekcie vw mamy od razu
wpisane dane więc od razu jest koszt wyliczany.
*/

#include <iostream>
using namespace std;

class koszt {
private:
    double zuzycie;
    double cena;

public:
    koszt();
    koszt(double x, double y);
    ~koszt();

    void set_zuzycie(double x);
    void set_cena(double x);

    double get_zuzycie() const;
    double get_cena() const;

    double wylicz() const;
};

// konstruktor domyślny (delegowanie)
koszt::koszt() : koszt(0.0, 0.0) {}

// konstruktor parametrowy
koszt::koszt(double x, double y) : zuzycie(x), cena(y) {}

koszt::~koszt() {}

void koszt::set_zuzycie(double x) {
    zuzycie = x;
}

void koszt::set_cena(double x) {
    cena = x;
}

double koszt::get_zuzycie() const {
    return zuzycie;
}

double koszt::get_cena() const {
    return cena;
}

double koszt::wylicz() const {
    return (zuzycie / 100.0) * cena;
}

int main(int argc, char** argv) {
    double z;
    double c;

    cout << "Policzmy koszt jednego kilometra dla Opel: " << endl;
    cout << "Podaj zuzycie paliwa: ";
    cin >> z;
    cout << "Podaj cene paliwa: ";
    cin >> c;

    koszt opel; // konstruktor domyslny

    cout << "Koszt: " << opel.wylicz() << " zl.za km" << endl; // (1)

    opel.set_zuzycie(z);
    opel.set_cena(c);

    cout << "jeszcze raz koszt: " << opel.wylicz() << " zl.za km" << endl << endl; // (2)

    cout << "Policzmy koszt jednego kilometra dla VW: " << endl;
    cout << "Podaj zuzycie paliwa: ";
    cin >> z;
    cout << "Podaj cene paliwa: ";
    cin >> c;

    koszt vw(z, c); // konstruktor parametrowy

    cout << "Koszt: " << vw.wylicz() << " zl.za km" << endl;

    return 0;
}
/*
Zadanie 2.Jest napisany program do wyliczania mocy. Mechanizm wyliczania jest
zawarty w klasie „moc”. Mamy tam 4 konstruktory. Uzupełnij brakujące metody o
ciało. Klasa wygląda w ten sposób:class moc{private:int volt;double amper;double
wat;void wylicz(void) {wat=volt*amper;}public:moc(): volt(0), amper(0.0),
wat(0.0) {}//konstruktor 1moc(int a): volt(a), amper(0.0)
{wylicz();}//konstruktor 2moc(double a): volt(230), amper(a)
{wylicz();}//konstruktor 3moc(int a, double b): volt(a), amper(b)
{wylicz();}//konstruktor 4~moc(void) {}void set_volt(int a) {volt=a;}void
set_amper(int a);double get_wat(void);};Funkcja main działającego program
wygląda w ten sposób: int main(int argc, char** argv) {int v;double a;cout<<"Moc
silnika"<<endl;cout<<"Podaj napiecie: ";cin>>v;cout<<"Podaj prad: ";cin>>a;moc
silnik(v,a);cout<<"Moc silnika to:
"<<silnik.get_wat()<<"W"<<endl;cout<<endl<<"Moc zarowki"<<endl;cout<<"Podaj
napiecie: ";cin>>v;cout<<"Podaj prad: ";cin>>a;moc zarowka(a);cout<<"Moc zarowki
to: "<<zarowka.get_wat()<<"W"<<endl;cout<<endl<<"Moc
komputera"<<endl;cout<<"Podaj napiecie: ";cin>>v;cout<<"Podaj prad: ";cin>>a;moc
komp(v);cout<<"Moc komputera to: "<<komp.get_wat()<<"W"<<endl; cout<<endl<<"Moc TV"<<endl;cout<<"Podaj napiecie:
";cin>>v;cout<<"Podaj prad: ";cin>>a;moc tv;cout<<"Moc TV to:
"<<tv.get_wat()<<"W"<<endl;return 0;}Zastanów się i uzupełnij tabelkę który
konstruktor jest wywoływany Obiekt:Konstruktor:silnikzarowkakomptvZ
*/

#include <iostream>
using namespace std;

class moc {
private:
    int volt;
    double amper;
    double wat;

    void wylicz() {
        wat = volt * amper;
    }

public:
    // Konstruktor domyślny
    moc() : volt(0), amper(0.0), wat(0.0) {}

    // Konstruktor główny
    moc(int v, double a) : volt(v), amper(a) {
        wylicz();
    }

    ~moc() {}

    void set_volt(int v) {
        volt = v;
        wylicz();
    }

    void set_amper(double a) {
        amper = a;
        wylicz();
    }

    double get_wat() const {
        return wat;
    }
};

int main() {
    int v;
    double a;

    cout << "Moc silnika" << endl;
    cout << "Podaj napiecie: ";
    cin >> v;
    cout << "Podaj prad: ";
    cin >> a;

    moc silnik(v, a);
    cout << "Moc silnika to: " << silnik.get_wat() << "W" << endl;

    cout << endl << "Moc zarowki" << endl;
    cout << "Podaj napiecie: ";
    cin >> v;
    cout << "Podaj prad: ";
    cin >> a;

    // jeśli chcesz domyślne napięcie np. 230V, ustaw je jawnie:
    moc zarowka(230, a);
    cout << "Moc zarowki to: " << zarowka.get_wat() << "W" << endl;

    cout << endl << "Moc komputera" << endl;
    cout << "Podaj napiecie: ";
    cin >> v;
    cout << "Podaj prad: ";
    cin >> a;

    moc komp(v, a);
    cout << "Moc komputera to: " << komp.get_wat() << "W" << endl;

    cout << endl << "Moc TV" << endl;
    cout << "Podaj napiecie: ";
    cin >> v;
    cout << "Podaj prad: ";
    cin >> a;

    moc tv;
    tv.set_volt(v);
    tv.set_amper(a);

    cout << "Moc TV to: " << tv.get_wat() << "W" << endl;

    return 0;
}

/*
Zadanie 4.Zadanie to ma zaprezentować zbudowanie klasy z zastosowaniem szablonu.
Klasa nazywa się „kalkulator” i w sumie dodaje dwie cyfry, odejmuje dwie cyfry.
Oprócztego ma dwa konstruktory oraz destruktor oraz dwie metody do wczytywania
cyfr. Dzięki zastosowaniu szablonu wykonamy jedną klasę która jest uniwersalna
dlaróżnych typów zmiennych.Klasa kalkulator:template<class T>class
kalkulator{private:T liczba1;T liczba2;public:kalkulator(void): liczba1(0),
liczba2(0) {}kalkulator(T a, T b): liczba1(a), liczba2(b) {}~kalkulator(void) {}
void liczba1_set(T a);void liczba2_set(T b);T dodawanie(void);T
odejmowanie(void);void klawiatura(void);};Dla ułatwienia przedstawię ciało
jednej metodytemplate<class T>void kalkulator<T>::klawiatura(void){cout<<"Podaj
pierwsza liczba: ";cin>>liczba1;cout<<"Podaj druga liczba:
";cin>>liczba2;}Dopisz brakujące metody. Następnie w funkcji main sprawdź
działanie klasyint main(int argc, char** argv) {kalkulator<int>
kal(3,4);//(1)cout<<"suma "<<kal.dodawanie()<<endl;cout<<"Podaj liczbe w
double"<<endl;kalkulator<double> moje;//(2)moje.klawiatura();cout<<"roznica
"<<moje.odejmowanie()<<endl;return 0;}W funkcji mainmamy dwa obiekty typu
kalkulator. Pierwszy obiekt nazywa się „kal” i został zbudowany za pomocą klasy
kalkulator. Klasa w tym wypadku działa na zmiennych typu int (linia 1). Widzimy
to w tym zapisie „<int>”. Lina 1 wywołuje konstruktor parametrowy. W linii 2
widzimy obiekt który nazywa się „moje”. Został zbudowany za pomocą klasy
kalkulator gdzie w tym wypadku klasa będzie działać na zmiennych typu double.
Linia 2 pokazuje wywołanie konstruktora bezargumentowego.
*/

#include <iostream>
using namespace std;

template<class T>
class kalkulator {
private:
    T liczba1;
    T liczba2;
public:
    kalkulator(void) : liczba1(0), liczba2(0) {}
    kalkulator(T a, T b) : liczba1(a), liczba2(b) {}
    ~kalkulator(void) {}
    void liczba1_set(T a) { liczba1 = a; }
    void liczba2_set(T b) { liczba2 = b; }
    T dodawanie(void) { return liczba1 + liczba2; }
    T odejmowanie(void) { return liczba1 - liczba2; }
    void klawiatura(void) {
        cout << "Podaj pierwsza liczba: ";
        cin >> liczba1;
        cout << "Podaj druga liczba: ";
        cin >> liczba2;
    }
};

int main(int argc, char** argv) {
    kalkulator<int> kal(3, 4); // (1)
    cout << "suma " << kal.dodawanie() << endl;
    cout << "Podaj liczbe w double" << endl;
    kalkulator<double> moje; // (2)
    moje.klawiatura();
    cout << "roznica " << moje.odejmowanie() << endl;
    return 0;
}   


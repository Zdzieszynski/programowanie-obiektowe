/*



Zadanie 6.Napisz program na podstawie klasy z zadania 5 tak aby pobierał cyfry z
klawiatury a następnie liczba 0 kończy wczytywanie z klawiatury (tak samo jak w
zadaniu 5). Jednak chcę aby wypisać sumę liczb parzystych oraz sumę liczb
nieparzystych.

Treść zadania 5 (Zadanie 5.Program ma za zadanie zliczać cyfry podane z klawiatury przez
użytkownika. Program pobiera cyfry i zlicza sumę tak długo aż użytkownik poda
cyfrę zero. Cyfra zero kończy pobieranie cyfr i wyświetla sumę. Program został
napisany w funkcji main, natomiast cała logika programu jest zawarta w klasie o
nazwie „sumator”. Funkcja main jest bardzo prosta i wygląda w ten sposób:int
main(int argc, char** argv) {sumator S;cout<<"Program sumuje liczby, liczba 0
konczy sumowanie"<<endl;doS.pobierz();while(S.koniec());cout<<"Suma
wprowadzonych liczb to: "<<S.suma();return 0;}Ciała metod klasy sumator
wyglądają w ten sposób:void sumator::pobierz(void){int temp;cout<<"Wpisz liczbe
aby ja dodac: ";cin>>temp;if(temp==0) _koniec=0;else_suma+=temp;}int
sumator::koniec(void){return _koniec;}intsumator::suma(void){return
_suma;}Dopisz brakującą część programu czyli uzupełnij klasę sumator:class
sumator{private:public:};)
*/

#include <iostream>
using namespace std;
class sumator {
private:
    int _suma_parzystych = 0;
    int _suma_nieparzystych = 0;
    int _koniec = 1;
public:
    sumator() {}
    void pobierz(void);
    int koniec(void);
    int suma_parzystych(void);
    int suma_nieparzystych(void);
};

void sumator::pobierz(void) {
    int temp;
    cout << "Wpisz liczbe aby ja dodac: ";
    cin >> temp;
    if (temp == 0)
        _koniec = 0;
    else if (temp % 2 == 0)
        _suma_parzystych += temp;
    else
        _suma_nieparzystych += temp;
}

int sumator::koniec(void) {
    return _koniec;
}

int sumator::suma_parzystych(void) {
    return _suma_parzystych;
}

int sumator::suma_nieparzystych(void) {
    return _suma_nieparzystych;
}

int main(int argc, char** argv) {
    sumator S;
    cout << "Program sumuje liczby, liczba 0 konczy sumowanie" << endl;
    do
        S.pobierz();
    while (S.koniec());
    cout << "Suma wprowadzonych liczb parzystych to: " << S.suma_parzystych() << endl;
    cout << "Suma wprowadzonych liczb nieparzystych to: " << S.suma_nieparzystych() << endl;
    return 0;
}

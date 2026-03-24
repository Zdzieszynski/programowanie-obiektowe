/*
Zadanie 7.Ułóż program z układanki gdzie tworzymy zmienną dynamiczną typu int i
ustawiamy wskaźnik który nazywa się temp, wpisujemy do tej zmiennej liczbę 10,
wypisujemy na ekran liczbę przez wskaźnik temp, wypisujemy na ekran adres
zmiennej dynamicznej, tworzymy drugi wskaźnik który nazywa się ws, ustawiamy
wskaźnik ws na zmienną dynamiczną, wpisujemy cyfrę 20 przez wskaźnik ws,
wypisujemy na ekran cyfrę wskaźnikiem ws. Aby wskaźniki unique_ptr działały musi
być co najmniej kompilator c++14 lub nowszy.unique_ptr<int> temp (new
int);unique_ptr<int>
ws;cout<<temp.get()<<endl;cout<<*temp<<endl;*temp=10;#include
<memory>ws=move(temp);
*/

#include <iostream>
#include <memory>
using namespace std;
int main() {
    unique_ptr<int> temp(new int);
    *temp = 10;
    cout << *temp << endl;
    cout << temp.get() << endl;

    unique_ptr<int> ws;
    ws = move(temp);
    *ws = 20;
    cout << *ws << endl;

    return 0;
}


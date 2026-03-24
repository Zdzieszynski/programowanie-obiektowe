/*
Zadanie 8.Ułóż program z układanki gdzie tworzymy zmienną dynamiczną typu „test”
(tak nazywa się klasa) i ustawiamy wskaźnik który nazywa się „t”, wyświetlamy
adres zmiennej dynamicznej, wczytujemy liczbę 5, wyświetlamy na ekran terminala
cyfrę ze zmiennej dynamicznej, tworzymy drugi wskaźnik który nazywa się „t2” i
ustawiamy go na zmienną dynamiczną, wypisujemy na ekran cyfrę za pomocą
wskaźnika „t2”. Aby wskaźniki unique_ptr działały musi być co najmniej
kompilator c++14 lub nowszy.t->set_a(5);unique_ptr<test> t(new
test);unique_ptr<test> t2=move(t);cout<<t.get()<<endl;cout<<t2->get_a()<<endl;
cout<<t->get_a()<<endl;Klasa będzie wyglądała w ten sposób:class
test{private:int a;public:test(){ a=0;}void set_a(int x) {a=x;}int get_a(void)
{return a;}};
*/

#include <iostream>
#include <memory>

using namespace std;
class test {
private:
    int a;
public:
    test() { a = 0; }
    void set_a(int x) { a = x; }
    int get_a(void) { return a; }
};

int main() {
    unique_ptr<test> t(new test);
    t->set_a(5);
    cout << t.get() << endl;

    unique_ptr<test> t2 = move(t);
    cout << t2->get_a() << endl;
    cout << t->get_a() << endl;

    return 0;
}
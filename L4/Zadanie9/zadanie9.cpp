/*
Zadanie 9.Program pokazuje podstawowe działania na kontenerze „vector”. Tworzymy
wektor zczterema cyframi a następnie dodajemy jedną cyfrę 15 na pozycji drugiej.
Następnie wypisujemy na ekran wszystkie cyfry. Twoim zadaniem jest wstawić
jeszcze liczbę 25 między cyfry 20 a 30 oraz wstawić liczbę 35 między cyfrę 30 a
40.#include <iostream>#include <vector>using namespace std;int main() {//
Tworzymy wektor liczb całkowitychvector<int> vec;// Dodajemy elementy do
wektora// vec.push_back(10);// vec.push_back(20);// vec.push_back(30);//
vec.push_back(40);//lubdodajemy jedną liniąvec= {10, 20, 30, 40};//dodajemy
jeden element 15 na drugim miejscuvec.insert(vec.begin() + 1, 15);// Wypisujemy
elementy wektoracout << "Elementy wektora: " << endl;for (int i = 0; i <
vec.size(); i++) {cout << vec[i] << endl;}return 0;}
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
    // Tworzymy wektor liczb całkowitych
    vector<int> vec;

    // Dodajemy elementy do wektora
    vec = {10, 20, 30, 40};

    // Dodajemy jeden element 15 na drugim miejscu
    vec.insert(vec.begin() + 1, 15);

    // Wstawiamy liczbę 25 między cyfry 20 a 30
    vec.insert(vec.begin() + 3, 25);

    // Wstawiamy liczbę 35 między cyfrę 30 a 40
    vec.insert(vec.begin() + 5, 35);

    // Wypisujemy elementy wektora
    cout << "Elementy wektora: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return 0;
}   


/*Zadanie 5.Napisz program, który zadeklaruje tablice 20 
elementową, a następnie prosi użytkownika o wpisanie cyfr z
 klawiatury i zapisanie do tablicy. Następnie program wypisuje:
  największą cyfrę, najmniejszą cyfrę, sumę cyfr liczb parzystych.*/

#include <iostream>
using namespace std;
int main() {
    const int SIZE = 20;
    int numbers[SIZE];

    cout << "Podaj " << SIZE << " cyfr:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];
    }

    int maxNum = numbers[0];
    int minNum = numbers[0];
    int sumEven = 0;

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] > maxNum) {
            maxNum = numbers[i];
        }
        if (numbers[i] < minNum) {
            minNum = numbers[i];
        }
        if (numbers[i] % 2 == 0) {
            sumEven += numbers[i];
        }
    }

    cout << "Największa cyfra: " << maxNum << endl;
    cout << "Najmniejsza cyfra: " << minNum << endl;
    cout << "Suma cyfr parzystych: " << sumEven << endl;
    return 0;
}
/*
Zadanie 1.Napisz program, który dodaje cyfry podane z klawiatury
przez użytkownika, cyfra 0 kończy program i wyświetla
sumę wczytanych cyfr. Chodzi o to że gdy użytkownik poda
cyfry: 1,2,3,0 program wyświetli 6.
Gdy użytkownik poda cyfry: 2,2,0 program wyświetli 4.
*/

#include <iostream>
int main() {
    int sum = 0;
    int digit;

    std::cout << "Podaj cyfry (0 kończy program): ";
    while (true) {
        std::cin >> digit;
        if (digit == 0) {
            break; // Kończy program, gdy użytkownik poda 0
        }
        sum += digit; // Dodaje wczytaną cyfrę do sumy
    }

    std::cout << "Suma wczytanych cyfr: " << sum << std::endl;
    return 0;
}
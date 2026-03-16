/*
Zadanie 2.Napisz program, który tworzy trzy zmienne
dynamiczne. Pierwsza zmienna to podstawa,
druga i trzecia to boki. Następnie program wypisuje czy to
jest trójkąt równoboczny oraz czy jest to trójkąt
równoramienny.
*/

#include <iostream>
#include <Windows.h> // Biblioteka do ustawiania kodowania konsoli

int main() {
    // Ustawienie UTF-8 w konsoli    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double* base = new double; // Dynamiczna zmienna dla podstawy
    double* side1 = new double; // Dynamiczna zmienna dla pierwszego boku
    double* side2 = new double; // Dynamiczna zmienna dla drugiego boku

    std::cout << "Podaj długość podstawy: ";
    std::cin >> *base;
    std::cout << "Podaj długość pierwszego boku: ";
    std::cin >> *side1;
    std::cout << "Podaj długość drugiego boku: ";
    std::cin >> *side2;

    // Sprawdzenie, czy jest to trójkąt równoboczny
    if (*base == *side1 && *side1 == *side2) {
        std::cout << "To jest trójkąt równoboczny." << std::endl;
    } else {
        std::cout << "To nie jest trójkąt równoboczny." << std::endl;
    }

    // Sprawdzenie, czy jest to trójkąt równoramienny
    if (*base == *side1 || *base == *side2 || *side1 == *side2) {
        std::cout << "To jest trójkąt równoramienny." << std::endl;
    } else {
        std::cout << "To nie jest trójkąt równoramienny." << std::endl;
    }

    // Zwolnienie pamięci dynamicznej
    delete base;
    delete side1;
    delete side2;

    return 0;
}

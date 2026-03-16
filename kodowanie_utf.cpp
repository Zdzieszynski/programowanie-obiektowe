#include <iostream>
//#include <clocale> // Biblioteka do polskich znaków

using namespace std;

int main() {
    // Ta linia w połączeniu z Twoim settings.json naprawia polskie znaki
    setlocale(LC_CTYPE, "Polish");

    cout << "Cześć! Terminal VS Code działa w UTF-8." << endl;
    cout << "Zażółć gęślą jaźń." << endl;
    
    int liczba;
    cout << "Podaj dowolną liczbę: ";
    cin >> liczba;
    cout << "Twoja liczba to: " << liczba << endl;

    return 0;
}

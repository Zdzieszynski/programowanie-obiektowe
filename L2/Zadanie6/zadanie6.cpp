#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
    double x1;
    double x2;
} wynik;

class rownanie {
private:
    int a;
    int b;
    int c;

public:
    rownanie(void);
    ~rownanie(void);
    void klawiatura(void);
    int delta(void);
    double jeden(void);
    wynik dwa(void);
};

rownanie::rownanie(void) {
    a = 0;
    b = 0;
    c = 0;
}

rownanie::~rownanie(void) {
}

void rownanie::klawiatura(void) {
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << "Podaj c: ";
    cin >> c;
}

int rownanie::delta(void) {
    double d = b*b - 4*a*c;
    if(d > 0)
        return 1;
    else if(d == 0)
        return 0;
    else
        return -1;
}

double rownanie::jeden(void) {
    return -b / (2.0 * a);
}

wynik rownanie::dwa(void) {
    wynik w;
    double d = sqrt(b*b - 4*a*c);
    w.x1 = (-b - d) / (2.0 * a);
    w.x2 = (-b + d) / (2.0 * a);
    return w;
}

int main(int argc, char** argv) {

    rownanie r;
    r.klawiatura();

    if(r.delta() == -1)
        cout << "nie ma miejsc zerowych" << endl;
    else if(r.delta() == 0) {
        cout << "jest jedno miejsce zerowe" << endl;
        cout << "x= " << r.jeden() << endl;
    }
    else {
        cout << "sa dwa miejsca zerowe" << endl;
        wynik temp;
        temp = r.dwa();
        cout << "x1= " << temp.x1 << endl;
        cout << "x2= " << temp.x2 << endl;
    }

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double monteCarloPi(int n) {
    srand(time(nullptr));

    int punktyWKole = 0;

    for (int i = 0; i < n; ++i) {
        double x = (static_cast<double>(rand()) / RAND_MAX) * 2 - 1;
        double y = (static_cast<double>(rand()) / RAND_MAX) * 2 - 1;

        if (x * x + y * y < 1.0)
            punktyWKole++;
    }

    return 4.0 * punktyWKole / n;
}

int main() {
    int n = 1000000; // liczba losowanych punktów

    double pi = monteCarloPi(n);

    cout << "Przyblizona wartosc liczby pi: " << pi << endl;

    return 0;
}

/*  rand() - losuje inta od 0 do RAND_MAX
 *  (static_cast<double>(rand()) /RAND_MAX) konwertuje int-a na double z przedziału 0,1
 *  mnożąc *2 rozciągamy przedział od 0 do 2 i przesuwamy go w lewo, odejmując 1.
 *
 *
 */

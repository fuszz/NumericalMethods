#include <iostream>
#include <vector>

double horner(std::vector<double> wspolczynniki, double x) {
    double wynik = 0;
    for (int i = wspolczynniki.size() - 1; i >= 0; --i)
        wynik = wynik * x + wspolczynniki[i];
    return wynik;
}

int main() {
    std::vector<double> wspolczynniki = {5, -3, 2}; // Wielomian 2x^2 - 3x + 5
    double x = 1.5; // Punkt, w którym obliczamy wartość wielomianu

    std::cout << "Wartość wielomianu w punkcie " << x << " wynosi " << horner(wspolczynniki, x) << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

std::vector<double> pochodna(std::vector<double> wspolczynniki) {
    std::vector<double> pochodna_wspolczynniki;
    for (int i = 1; i < wspolczynniki.size(); ++i)
        pochodna_wspolczynniki.push_back(i * wspolczynniki[i]);
    return pochodna_wspolczynniki;
}

double horner(std::vector<double> wspolczynniki, double x) {
    double wynik = 0;
    for (int i = wspolczynniki.size() - 1; i >= 0; --i)
        wynik = wynik * x + wspolczynniki[i];
    return wynik;
}

int main() {
    std::vector<double> wspolczynniki = {5, -3, 2}; // Wielomian 2x^2 - 3x + 5
    double x = 1.5; // Punkt, w którym obliczamy wartość wielomianu

    std::vector<double> pierwsza_pochodna = pochodna(wspolczynniki);
    std::vector<double> druga_pochodna = pochodna(pierwsza_pochodna);

    std::cout << "P(x) = " << horner(wspolczynniki, x) << std::endl;
    std::cout << "Wartość pierwszej pochodnej wielomianu w punkcie " << x << " wynosi " << horner(pierwsza_pochodna, x) << std::endl;
    std::cout << "Wartość drugiej pochodnej wielomianu w punkcie " << x << " wynosi " << horner(druga_pochodna, x) << std::endl;

    return 0;
}

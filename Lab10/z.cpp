#include <iostream>
#include <cmath>
using namespace std;

# define F f1
# define CAL_F cal_f1


// Definicja funkcji, którą chcemy zcałkować
double f1(double x) {
    return pow(x, 2);  // Przykładowa funkcja x^2
}

double cal_f1(double x) {
    return pow(x, 3) / 3.0;
}

double f2(double x) {
    return cos(x);
}

double cal_f2(double x) {
    return sin(x);
}

double f3(double x) {
    return 1/x;
}

double cal_f3(double x) {
    return log(x);
}

double metoda_prostokatow(double a, double b, int n) {
    double h = (b - a) / n;  // Szerokość prostokąta
    double integral = 0.0;

    for(int i = 0; i < n; i++) {
        // Wysokość prostokąta to wartość funkcji w środku przedziału
        double x = a + h * (i + 0.5);
        integral += F(x);
    }

    integral *= h;  // Całka to suma pól prostokątów
    return integral;
}

double metoda_trapezow(double a, double b, int n) {
    double h = (b - a) / n;  // Szerokość trapezu
    double integral = 0.5 * (F(a) + F(b));  // Pierwszy i ostatni trapez

    for(int i = 1; i < n; i++) {
        double x = a + h * i;
        integral += F(x);
    }

    integral *= h;  // Całka to suma pól trapezów
    return integral;
}

double sprawdzenie(double a, double b) {
    return CAL_F(b) - CAL_F(a);
}

int main() {
    double a = 0.0;  // Dolna granica całki
    double b = 1;  // Górna granica całki
    int n = 1000;  // Liczba prostokątów

    double integral = metoda_prostokatow(a, b, n);
    cout << "Wartosc calki: " << integral << endl;
    cout << "Sprawdzenie: " << sprawdzenie(a, b) << endl;
    integral = metoda_trapezow(a, b, n);
    cout << "Wartosc calki: " << integral << endl;
    return 0;
}

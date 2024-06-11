#include <iostream>
#include <cmath>

using namespace std;

double norma_euklidesowa(double* wektor, int liczba_elementow) {
    // Pierwiastek kwadratowy z sumy wszystkich elementów wektora
    double suma = 0;
    for(int i=0; i<liczba_elementow; i++){
        suma+=pow(wektor[i], 2);
    }
    return sqrt(suma);
}

double norma_maksymalna(double* wektor, int liczba_elementow) {
    // Maksymalna wartość spośród wszystkich wartości bezwzgl. elementów, n. Frobeniusa
    double suma = wektor[0];
    for(int i=1; i<liczba_elementow; i++) {
        if(suma < wektor[i]) {
            suma = abs(wektor[i]);
        }
    }
    return suma;
}

double norma_manhattan(double* wektor, int liczba_elementow) {
    double sum = 0;
    for(int i=0; i<liczba_elementow; i++) {
        sum += abs(wektor[i]);
    }
    return sum;
}

int main() {
    int liczba_elementow = 5;
    double wektor[liczba_elementow]={1, 2, 3, 4, 5};

    cout<<"Norma euklidesowa: "<<norma_euklidesowa(wektor, liczba_elementow)<<endl;
    cout<<"Norma maksymalna: "<<norma_maksymalna(wektor, liczba_elementow)<<endl;
    cout<<"Norma Manhattan: "<<norma_manhattan(wektor, liczba_elementow)<<endl;
    return 0;
}


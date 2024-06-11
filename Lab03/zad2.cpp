#include <vector>
#include <iostream>

using namespace std;

// Funkcja zwracająca transpozycję macierzy
vector<vector<double>> transpozycja(const vector<vector<double>>& macierz) {
    // Sprawdzanie wymiarów macierzy
    int wiersze = macierz.size();
    int kolumny = macierz[0].size();

    // Tworzenie macierzy wynikowej o wymienionych wymiarach
    vector<vector<double>> transponowana(kolumny, vector<double>(wiersze));

    // Pętle przechodzące przez elementy oryginalnej macierzy
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            // Zamiana miejscami wierszy i kolumn
            transponowana[j][i] = macierz[i][j];
        }
    }

    // Zwracanie transponowanej macierzy
    return transponowana;
}

int main() {
    // Przykładowa macierz
    vector<vector<double>> macierz = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Obliczanie transpozycji macierzy
    vector<vector<double>> transponowana = transpozycja(macierz);

    // Wyświetlanie transponowanej macierzy
    for (int i = 0; i < transponowana.size(); ++i) {
        for (int j = 0; j < transponowana[0].size(); ++j) {
            cout << transponowana[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

double wyznacznik(const vector<vector<double>>& macierz);
vector<vector<double>> dopełnienia(const vector<vector<double>>& macierz);
vector<vector<double>> transpozycja(const vector<vector<double>>& macierz);

vector<vector<double>> odwrotnaLaplace(const vector<vector<double>>& macierz) {
    int rozmiar = macierz.size();
    double det = wyznacznik(macierz);
    if (det == 0) {
        cerr << "Macierz nie ma odwrotności." << endl;
        return vector<vector<double>>();
    }

    vector<vector<double>> macierzOdwrotna(rozmiar, vector<double>(rozmiar));

    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            vector<vector<double>> podmacierz(rozmiar - 1, vector<double>(rozmiar - 1));
            int m = 0, n = 0;
            for (int k = 0; k < rozmiar; ++k) {
                if (k != i) {
                    n = 0;
                    for (int l = 0; l < rozmiar; ++l) {
                        if (l != j) {
                            podmacierz[m][n] = macierz[k][l];
                            ++n;
                        }
                    }
                    ++m;
                }
            }
            macierzOdwrotna[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * wyznacznik(podmacierz) / det;
        }
    }

    macierzOdwrotna = transpozycja(macierzOdwrotna);

    return macierzOdwrotna;
}

double wyznacznik(const vector<vector<double>>& macierz) {
    int rozmiar = macierz.size();
    if (rozmiar == 1)
        return macierz[0][0];
    double det = 0;
    int znak = 1;
    for (int j = 0; j < rozmiar; ++j) {
        vector<vector<double>> podmacierz(rozmiar - 1, vector<double>(rozmiar - 1));
        for (int k = 1; k < rozmiar; ++k) {
            int l = 0;
            for (int m = 0; m < rozmiar; ++m) {
                if (m != j) {
                    podmacierz[k - 1][l] = macierz[k][m];
                    ++l;
                }
            }
        }
        det += znak * macierz[0][j] * wyznacznik(podmacierz);
        znak = -znak;
    }
    return det;
}

vector<vector<double>> dopełnienia(const vector<vector<double>>& macierz) {
    int rozmiar = macierz.size();
    vector<vector<double>> dopełnienia(rozmiar, vector<double>(rozmiar));
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            vector<vector<double>> podmacierz(rozmiar - 1, vector<double>(rozmiar - 1));
            int m = 0, n = 0;
            for (int k = 0; k < rozmiar; ++k) {
                if (k != i) {
                    n = 0;
                    for (int l = 0; l < rozmiar; ++l) {
                        if (l != j) {
                            podmacierz[m][n] = macierz[k][l];
                            ++n;
                        }
                    }
                    ++m;
                }
            }
            dopełnienia[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * wyznacznik(podmacierz);
        }
    }
    return dopełnienia;
}

vector<vector<double>> transpozycja(const vector<vector<double>>& macierz) {
    int wiersze = macierz.size();
    int kolumny = macierz[0].size();
    vector<vector<double>> transponowana(kolumny, vector<double>(wiersze));
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            transponowana[j][i] = macierz[i][j];
        }
    }
    return transponowana;
}

int main() {
    vector<vector<double>> macierz = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    vector<vector<double>> odwrotna = odwrotnaLaplace(macierz);

    cout << "Macierz odwrotna (rozwinięcie Laplace'a):" << endl;
    for (int i = 0; i < odwrotna.size(); ++i) {
        for (int j = 0; j < odwrotna[0].size(); ++j) {
            cout << odwrotna[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

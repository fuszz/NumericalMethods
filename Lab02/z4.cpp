#include <vector>
#include <iostream>

using namespace std;

void wyswietl_macierz(vector<vector<double>> a) {
    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<a[0].size(); j++) {
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
}

vector<vector<double> > mnozenie_macierzy(vector<vector<double> > a, vector<vector<double> > b) {
    if(a[0].size() != b.size()) {
        cout<<"Niepoprawne wymiary macierzy. Mnozenie niemozliwe"<<endl;
        return {{-1.0}};
    }

    vector<vector<double>> wynik(a.size(), vector<double>(b[0].size(), 0.0));

    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<b[0].size(); j++) {
            double sum = 0;
            for(int k=0; k<b.size(); k++) {
                sum += a[i][k] * b[k][j];
            }
            wynik[i][j] = sum;
        }
    }
    return wynik;
}

int main() {
    vector<vector<double> > a = {
        {1, 2, 3},
        {1, 2, 3}
    };

    vector<vector<double> > b = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
    };

    wyswietl_macierz(mnozenie_macierzy(a, b));

    return 0;
}


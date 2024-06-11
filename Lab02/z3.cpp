#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double norma_frobeiunsa(vector<vector<double> > v1) {
    double suma = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[0].size(); j++) {
            suma += pow(v1[i][j], 2);
        }
    }
    return sqrt(suma);
}

double norma_maksymalna(vector<vector<double> > v1) {
    double maks = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[0].size(); j++) {
            if (maks < abs(v1[i][j])) {
                maks = abs(v1[i][j]);
            }
        }
        return maks;
    }
}

double norma_manhattan(vector<vector<double> > v1) {
    double suma = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[0].size(); j++) {
            suma += abs(v1[i][j]);
        }
        return suma;
    }
}


int main() {
    vector<vector<double> > v1 = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };

    cout << "Norma Frobeiunsa: " << norma_frobeiunsa(v1) << endl;
    cout << "Norma Manhattan: " << norma_manhattan(v1) << endl;
    cout << "Norma maksymalna: " << norma_maksymalna(v1) << endl;
    return 0;
}

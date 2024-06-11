#include <vector>
#include <cmath>
#include <iostream>

double wyznacznik(const std::vector<std::vector<double>>& a) {
    int n = a.size();
    if (n == 0 || n != a[0].size()) {
        std::cerr << "Macierz nie jest kwadratowa." << std::endl;
        return 0;
    }
    if (n == 1)
        return a[0][0];
    
    double det = 0;
    int sign = 1;
    for (int i = 0; i < n; i++) {
        std::vector<std::vector<double>> submat(n - 1, std::vector<double>(n - 1));
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k < i)
                    submat[j-1][k] = a[j][k];
                else if (k > i)
                    submat[j-1][k-1] = a[j][k];
            }
        }
        det += sign * a[0][i] * wyznacznik(submat);
        sign = -sign;
    }
    return det;
}

int main() {
    std::vector<std::vector<double>> a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double w = wyznacznik(a);

    std::cout << "Wyznacznik macierzy to: " << w << std::endl;

    return 0;
}

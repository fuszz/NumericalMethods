#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* table(int n, int m ) {

    float* tab = (float*)malloc(n * sizeof(float));

    for(int i=0; i<n; i++) {
        tab[i]=0;
        for(int k=0; k<i; k++) {
            tab[i] = tab[i] + 1.0 / ((k % m) + 1) * ((k % m)+2);
        }
    }
    return tab;
}

int main(void)
{
    int n = pow(2, 10);
    int m = pow(2, 5);

    float* tab = table(n, m);

    for(int i=0; i<n; i++) {
        printf("%f\n", tab[i]);
    }

    free(tab);
}

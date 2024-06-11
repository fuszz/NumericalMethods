#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* table(int n, int m) {

    float* tab = (float*)malloc(n * sizeof(float));

    for(int i=0; i<n; i++) {
        tab[i]=0;
        for(int k=0; k<i; k++) {
            tab[i] = tab[i] + 1.0 / (((k % m) + 1) * ((k % m)+2));
        }
    }
    return tab;
}

float sum_of_table(float* tab, int n) {
    float sum = 0;
    for(int i=0; i<n; i++) {
        sum += tab[i];
    }
    return sum;
}

float real_sum_of_table(float n, float m) {
    return (float) n / (float) m+1;
}

int main(void)
{
    int n = pow(2, 10);
    int m = pow(2, 5);

    float* tab = table(n, m);

    for(int i=0; i<n; i++) {
        printf("%f\n", tab[i]);
    }

    float sum = sum_of_table(tab, n);
    printf("Sum: %f\n", sum);
    printf("Real sum: %f\n", real_sum_of_table(n, m));
    free(tab);
}

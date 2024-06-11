#include <stdio.h>

int main(void)
{
    float a = 0.1, b = -1, c = 0.9;
    printf("%.20f\n", (a+b)+c);
    printf("%.20f\n", a+(b+c));
}

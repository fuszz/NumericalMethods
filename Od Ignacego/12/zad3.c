#include <stdio.h>
#include <math.h>
#include <limits.h>

unsigned int X (unsigned int n, unsigned int X0, unsigned int a, unsigned int c, unsigned int M)
{
	if (n == 0)
		return (a * X0 + c )% M;
	return (a * X (n - 1, X0, a, c, M) + c) % M;
}

int main ()
{
	//20.000/32=625
	unsigned int ones = 0;
	for (unsigned int i = 0; i < 625; i++)
		ones += __builtin_popcount(X (i, 1, 75, 74, UINT_MAX));
	printf ("%d\n", ones);
	return 0;
}

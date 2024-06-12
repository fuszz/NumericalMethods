#include <stdio.h>

int X (int n, int X0, int X1, int q, int p, int M)
{
	if (n == 0)
		return X0 % M;
	if (n == 1)
		return X1 % M;
	return (X (n-q,X0,X1,q,p,M) + X (n-p,X0,X1,q,p,M)) % M;
}

int main ()
{
	for (int i = 0; i < 20; i++)
		printf ("%d\n", X (i, 1, 2, 2, 1, 5));
	return 0;
}

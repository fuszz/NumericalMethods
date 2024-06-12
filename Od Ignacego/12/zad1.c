#include <stdio.h>
#include <math.h>

int X (int n, int X0, int a, int c, int M)
{
	if (n == 0)
		return (a * X0 + c )% M;
	return (a * X (n - 1, X0, a, c, M) + c) % M;
}

int main ()
{
	for (int i = 0; i < 20; i++)
		printf ("(%d,%d),", X (i, 3, 2, 3, 10), X (i + 1, 3, 2, 3, 10));
	printf ("\n");

	for (int i = 0; i < 200; i+=2)
		printf ("<circle r=\"5\" cx=\"%d\" cy=\"%d\" fill=\"red\" />\n", X (i, 1, 75, 74, pow (2, 16) + 1) % 1000, X (i + 1, 1, 75, 74, pow (2, 16) + 1) % 1000);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

double horner (double *a, double x, int n)
{
	double p = 0.;
	for (int i = n; i >= 0; i--)
	{
		p = p * x + a[i];
	}
	return p;
}

int main ()
{
	int n;
	scanf ("%d", &n);

	double *a = malloc (sizeof (double) * (n + 1));
	for (int i = n; i >= 0; i--)
		scanf ("%lf", a + i);

	double x;
	scanf ("%lf", &x);

	printf ("%lf\n", horner (a, x, 3));
	
	free (a);
	return 0;
}

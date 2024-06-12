#include <stdio.h>
#include <stdlib.h>

double horner_p1 (double *a, double x, int n)
{
	double p = 0.;
	for (int i = n; i > 0; i--)
	{
		p = p * x + i * a[i];
	}
	return p;
}

double horner_p2 (double *a, double x, int n)
{
	double p = 0.;
	for (int i = n; i > 1; i--)
	{
		p = p * x + i * (i - 1) * a[i];
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

	printf ("%lf\n", horner_p1 (a, x, 3));
	printf ("%lf\n", horner_p2 (a, x, 3));
	
	free (a);
	return 0;
}

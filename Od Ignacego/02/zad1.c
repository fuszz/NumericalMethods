#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double norma_euklidesowa (int *v, int n)
{
	double ret = 0.;
	for (int i = 0; i < n; i++)
	{
		ret += v[i] * v[i];
	}
	return sqrt (ret);
}

double norma_manhattan (int *v, int n)
{
	double ret = 0.;
	for (int i = 0; i < n; i++)
	{
		ret += abs(v[i]);
	}

	return ret;
}

double norma_maximum (int *v, int n)
{
	double ret = 0.;
	for (int i = 0; i < n; i++)
	{
		double tmp = abs (v[i]);

		if (tmp > ret)
			ret = tmp;
	}

	return ret;
}

int main ()
{
	int n;
	scanf ("%d", &n);

	int *v = malloc (sizeof (int) * n);

	for (int i = 0; i < n; i++)
		scanf ("%d", &v[i]);

	printf ("%lf\n", norma_euklidesowa (v, n));
	printf ("%lf\n", norma_manhattan (v, n));
	printf ("%lf\n", norma_maximum (v, n));
	return 0;
}

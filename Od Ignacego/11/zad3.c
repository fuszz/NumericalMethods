#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

double complex horner (double complex *a, double complex x, int n)
{
	double complex p = 0.;
	for (int i = n; i >= 0; i--)
	{
		p = p * x + a[i];
	}
	return p;
}

double complex horner_p1 (double complex *a, double complex x, int n)
{
	double complex p = 0.;
	for (int i = n; i > 0; i--)
	{
		p = p * x + i * a[i];
	}
	return p;
}

double complex horner_p2 (double complex *a, double complex x, int n)
{
	double complex p = 0.;
	for (int i = n; i > 1; i--)
	{
		p = p * x + i * (i - 1) * a[i];
	}
	return p;
}

double complex laguerre (double complex *p, double complex x, int n)
{
	double complex G, H, s, a;
	for (int i = 0; i < 100; i++)
	{
		double complex y = horner_p1 (p, x, n);
		double complex z = horner (p, x, n);

		if (abs (creal (z)) < 0.00001 && abs (cimag (z) < 0.00001))
			return x;

		G = horner_p1 (p, x, n) / horner (p, x, n);
		H = G * G - horner_p2 (p, x, n) / horner (p, x, n);
		s = csqrt ((n - 1) * (n * H - G * G));
		a = n / (abs (G - s) > abs (G + s) ? G - s : G + s);
		x = x - a;
	}

	return x;
}

int main ()
{
	int n;
	scanf ("%d", &n);

	double complex *a = malloc (sizeof (double complex) * (n + 1));
	double real;
	for (int i = n; i >= 0; i--)
	{
		scanf ("%lf", &real);
		*(a + i) = real + 0. * I;
	}

	double complex x;
	scanf ("%lf", &real);
	x = real + 0. * I;

	double complex r = laguerre (a, x, 3);
	printf ("%.2lf + %.2lfi\n", creal (r), cimag (r));
	
	free (a);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zad1 ()
{
	float a = 0.1, b = -1, c = 0.9;

	printf ("%.10f\n", (a + b) + c);
	printf ("%.10f\n", a + (b + c));
}

float *zad2 (int n, int m)
{
	float *ret = malloc (sizeof (float) * n);

	for (int k = 0; k < n; k++)
	{
		ret[k] = 1.f / ((k % m + 1.f) * (k % m + 2.f));
		printf ("%f ", ret[k]);
	}

	printf ("\n");

	return ret;
}

float zad3 (float *a, int n)
{
	float sum = 0.f;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	return sum;
}

float zad4 (float *a, int n)
{
	float s = 0.f, p = 0.f, s_old = 0.f;

	for (int i = 0; i < n; i++)
	{
		s = s_old + a[i];
		p = p + (a[i] - (s - s_old));
		s_old = s;
	}

	return s+p;
}

float zad6 (float *a, int n)
{
	float e = 0.f, s = 0.f;

	for (int i = 0; i < n; i++)
	{
		float tmp = s;
		float y = a[i] + e;
		s = tmp + y;
		e = (tmp - s) + y;
	}

	return s;
}


int main ()
{
	//zad1 ();
	//zad2
	float *a = zad2 (1<<20, 1<<5);	
	//zad3
	float sum = zad3 (a, 1<<20);
	float exact = (float) (1<<20) / (float) ((1<<5) + 1.f);
	printf ("%f\n", sum);
	float err = fabs(sum - exact) / exact;
	printf ("%e\n", err);
	//zad4
	float sum2 = zad4 (a, 1<<20);
	printf ("%f\n", sum2);
	float err2 = fabs(sum2 - exact) / exact;
	printf ("%e\n", err2);
	//zad6
	float sum3 = zad6 (a, 1<<20);
	printf ("%f\n", sum3);
	float err3 = fabs(sum3 - exact) / exact;
	printf ("%e\n", err3);
	return 0;
}

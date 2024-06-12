#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calk_prost (float a, float b, float n, float (*f)(float))
{
	float h = (b - a) / n;
	float s = 0.;

	for (int i = 0; i < n; i++)
	{
		s += f(a + h * (i + 0.5));
	}
	return h * s;
}

float calk_trap (float a, float b, float n, float (*f)(float))
{
	float h = (b - a) / n;
	float s = 0.;
	for (int i = 1; i < n; i++)
	{
		s += f (a + i * h);
	}

	return h * ((f (a) + f (b)) / 2. + s);

}

float calk_simp (float a, float b, float n, float (*f)(float))
{
	float h = (b - a) / n;

	float s1 = 0.;
	for (int i = 0; i < n; i++)
	{
		s1 += f (a + i * h + h / 2.);
	}

	float s2 = 0.;
	for (int i = 1; i < n; i++)
	{
		s2 += f (a + i * h);
	}

	return h / 6. * (f (a) + 4. * s1 + 2. * s2 + f (b));
}

float f1 (float x )
{
	return x * x;
}

float f2 (float x)
{
	return cos (x);
}

float f3 (float x)
{
	return 1. / x;
}

int main ()
{
	float a, b, n, s;
	n = 100;
	
	printf ("Prost:\n");

	a = 0., b = 1., s = calk_prost (a, b, n, f1);
	printf ("f=x^2\na=%f\nb=%f\nn=%f\ncalka=%f\nerr=%e\n\n",
			a, b, n, s, fabs (s - (1. / 3.)) / (1. / 3.));

	a = 0., b = M_PI / 2., s = calk_prost (a, b, n, f2);
	printf ("f=cos(x)\na=%f\nb=%f\nn=%f\ncalka=%f\nerr=%e\n\n",
			a, b, n, s, fabs (s - 1.) / 1.);

	a = M_E, b = pow (M_E, 2), s =calk_prost (a, b, n, f3);
	printf ("f=1/x\na=%f\nb=%f\nn=%f\ncalka=%e\nerr=%e\n\n",
			a, b, n, s, fabs (s - 1.) / 1.);

	printf ("Trapez:\n");

	a = 0., b = 1., s = calk_trap (a, b, n, f1);
	printf ("f=x^2\na=%f\nb=%f\nn=%f\ncalka=%f\nerr=%e\n\n",
			a, b, n, s, fabs (s - (1. / 3.)) / (1. / 3.));

	a = 0., b = M_PI / 2., s = calk_trap (a, b, n, f2);
	printf ("f=cos(x)\na=%f\nb=%f\nn=%f\ncalka=%f\nerr=%e\n\n",
			a, b, n, s, fabs (s - 1.) / 1.);

	a = M_E, b = pow (M_E, 2), s =calk_trap (a, b, n, f3);
	printf ("f=1/x\na=%f\nb=%f\nn=%f\ncalka=%e\nerr=%e\n\n",
			a, b, n, s, fabs (s - 1.) / 1.);

	printf ("Simps:\n");

	a = 0., b = 1., s = calk_simp (a, b, n, f1);
	printf ("f=x^2\na=%f\nb=%f\nn=%f\ncalka=%f\nerr=%e\n\n",
			a, b, n, s, fabs (s - (1. / 3.)) / (1. / 3.));

	a = 0., b = M_PI / 2., s = calk_simp (a, b, n, f2);
	printf ("f=cos(x)\na=%f\nb=%f\nn=%f\ncalka=%f\nerr=%e\n\n",
			a, b, n, s, fabs (s - 1.) / 1.);

	a = M_E, b = pow (M_E, 2), s =calk_simp (a, b, n, f3);
	printf ("f=1/x\na=%f\nb=%f\nn=%f\ncalka=%e\nerr=%e\n\n",
			a, b, n, s, fabs (s - 1.) / 1.);


	return 0;
}

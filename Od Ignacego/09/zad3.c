#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fa (double x) { return 2.0 * pow (x, 2.0) + 2.0; }
double pa (double x) { return 4.0 * x; }

double Newton (double x, double h, double (*f) (double)) {
	return (f (x + h) - f (x)) / h;
}

double Wsteczna (double x, double h, double (*f) (double)) {
	return (f (x) - f (x - h)) / h;
}

double Centralna (double x, double h, double (*f) (double)) {
	return (f (x + h) - f (x - h)) / (2.0 * h);
}

double Trzypunktowa_p (double x, double h, double (*f) (double)) {
	return (-3.0*f(x)+4.0*f(x+h)-f(x+2.0*h)) / (2.0 * h);
}

double Trzypunktowa_w (double x, double h, double (*f) (double)) {
	return (3.0*f(x)-4.0*f(x-h)+f(x-2.0*h)) / (2.0 * h);
}

double Czteropunktowa (double x, double h, double (*f) (double)) {
	return (f(x-2.*h)-8.*f(x-h)+8.*f(x+h)-f(x+2.*h))/(12.*h);
}

int main ()
{
	double x = 3.0, h1, h2, e1, e2;
	h1 = pow (10, -2);
	h2 = pow (10, -4);
	e1 = fabs (pa (x) - Newton (x, h1, fa)) / pa (x);
	e2 = fabs (pa (x) - Newton (x, h2, fa)) / pa (x);
	printf ("Newton\t\tx=%lf\th=%.1e\te=%.12e\n", x, h1, e1);
	printf ("Newton\t\tx=%lf\th=%.1e\te=%.12e\n", x, h2, e2);
	e1 = fabs (pa (x) - Wsteczna (x, h1, fa)) / pa (x);
	e2 = fabs (pa (x) - Wsteczna (x, h2, fa)) / pa (x);
	printf ("Wsteczna\tx=%lf\th=%.1e\te=%.12e\n", x, h1, e1);
	printf ("Wsteczna\tx=%lf\th=%.1e\te=%.12e\n", x, h2, e2);
	e1 = fabs (pa (x) - Trzypunktowa_p (x, h1, fa)) / pa (x);
	e2 = fabs (pa (x) - Trzypunktowa_p (x, h2, fa)) / pa (x);
	printf ("Trzpkt prz\tx=%lf\th=%.1e\te=%.12e\n", x, h1, e1);
	printf ("Trzpkt prz\tx=%lf\th=%.1e\te=%.12e\n", x, h2, e2);
	e1 = fabs (pa (x) - Trzypunktowa_w (x, h1, fa)) / pa (x);
	e2 = fabs (pa (x) - Trzypunktowa_w (x, h2, fa)) / pa (x);
	printf ("Trzpkt wst\tx=%lf\th=%.1e\te=%.12e\n", x, h1, e1);
	printf ("Trzpkt wst\tx=%lf\th=%.1e\te=%.12e\n", x, h2, e2);
	e1 = fabs (pa (x) - Czteropunktowa (x, h1, fa)) / pa (x);
	e2 = fabs (pa (x) - Czteropunktowa (x, h2, fa)) / pa (x);
	printf ("Czteropkt\tx=%lf\th=%.1e\te=%.12e\n", x, h1, e1);
	printf ("Czteropkt\tx=%lf\th=%.1e\te=%.12e\n", x, h2, e2);
	return 0;
}

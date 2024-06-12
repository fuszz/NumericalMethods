#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fa (double x) { return 2 * pow (x, 2) + 2; }
double pa (double x) { return 4 * x; }
double fb (double x) { return 2 * pow (x, 4) - pow (x, 2)+3*x-7; }
double pb (double x) { return 8 * pow (x, 3) - 2*x + 3; }
double fc (double x) { return pow (x, 2) * exp (x); }
double pc (double x) { return 2 * x * exp (x) +pow(x,2)*exp(x); }

double Newton (double x, double h, double (*f)())
{
	return (f(x + h) - f(x)) / h;
}

int main ()
{
	double x = 3, h1, h2, e1, e2;
	h1 = pow (10, -2);
	h2 = pow (10, -4);
	e1 = fabs(pa (x) - Newton (x, h1, fa)) / pa (x);
	e2 = fabs(pa (x) - Newton (x, h2, fa)) / pa (x);
	printf ("a) x=%lf h=%lf e=%lf\n", x, h1, e1);
	printf ("a) x=%lf h=%lf e=%lf\n", x, h2, e2);
	e1 = fabs(pb (x) - Newton (x, h1, fb)) / pb (x);
	e2 = fabs(pb (x) - Newton (x, h2, fb)) / pb (x);
	printf ("b) x=%lf h=%lf e=%lf\n", x, h1, e1);
	printf ("b) x=%lf h=%lf e=%lf\n", x, h2, e2);
	e1 = fabs(pc (x) - Newton (x, h1, fc)) / pc (x);
	e2 = fabs(pc (x) - Newton (x, h2, fc)) / pc (x);
	printf ("c) x=%lf h=%lf e=%lf\n", x, h1, e1);
	printf ("c) x=%lf h=%lf e=%lf\n", x, h2, e2);
	return 0;
}

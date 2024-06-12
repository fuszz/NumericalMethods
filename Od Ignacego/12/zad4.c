#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

unsigned int X (unsigned int n, unsigned int X0, unsigned int a, unsigned int c, unsigned int M)
{
	if (n == 0)
		return (a * X0 + c )% M;
	return (a * X (n - 1, X0, a, c, M) + c) % M;
}

int main ()
{
	//srand (time (NULL));
	double n = 10000;
	int circle = 0;
	for (int i = 0; i < n * 2; i+=2)
	{
		double x=X (i, time (NULL), 75, 74, pow (2, 16)) / pow (2, 16);
		//double x = rand () / (double) RAND_MAX;
		printf ("x=%lf\n", x);
		double y=X (i+1, time (NULL), 75, 74, pow (2, 16)) / pow (2, 16);
		//double y = rand () / (double) RAND_MAX;
		printf ("y=%lf\n", y);
		if (x*x + y*y <= 1)
			circle++;
		printf ("c=%d\n", circle);
	}
	printf ("%lf\n", 4. * circle / n);
	return 0;
}

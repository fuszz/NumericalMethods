#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define odleglosc_euklidesowa len

double odleglosc_euklidesowa (int x1, int y1, int x2, int y2)
{
	return sqrt ((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

double odleglosc_manhattan (int x1, int y1, int x2, int y2)
{
	return abs (x1 - x2) + abs (y1 - y2);
}

double odleglosc_maximum (int x1, int y1, int x2, int y2)
{
	double tmp = abs (x1-x2);
	double tmp2 = abs (y1-y2);
	return tmp > tmp2 ? tmp : tmp2;
}

double odleglosc_rzeka (int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
		return len (x1, y1, x2, y2);
	else
		return len (x1, y1, x1, 0) + len (x1, 0, x2, 0) + len (x2, 0, x2, y2);
}

double odleglosc_kolejowa (int x1, int y1, int x2, int y2)
{
	if (x1*y2 - x2 * y1 == 0)
		return len (x1, y1, x2, y2);
	else
		return len (x1, y1, 0, 0) + len (x2, y2, 0, 0);
}

int main ()
{
	int x1, y1, x2, y2;
	scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);

	printf ("%lf\n", odleglosc_euklidesowa (x1, y1, x2, y2));
	printf ("%lf\n", odleglosc_manhattan (x1, y1, x2, y2));
	printf ("%lf\n", odleglosc_maximum (x1, y1, x2, y2));
	printf ("%lf\n", odleglosc_rzeka (x1, y1, x2, y2));
	printf ("%lf\n", odleglosc_kolejowa (x1, y1, x2, y2));
	return 0;
}

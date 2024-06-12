#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double norma_rzeka (int **matrix, int n, int m)
{

}

int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);

	int **matrix = malloc (sizeof (int *) * n);

	for (int i = 0; i < n; i++)
	{
		matrix[i] = malloc (sizeof (int) * m);
		for (int j = 0; i < m; j++)
		{
			scanf ("%d", &matrix[i][j]);
		}
	}

	printf ("%lf\n", norma_rzeka (matrix, n, m));
	//printf ("%lf\n", norma_frobeiunsa (matrix, n, m));
	//printf ("%lf\n", norma_manhattan (matrix, n, m));
	//printf ("%lf\n", norma_kolejowa (matrix, n, m));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	int n1, m1;
	scanf ("%d %d", &n1, &m1);

	int **matrix1 = malloc (sizeof (int *) * n1);
	for (int i = 0; i < n1; i++)
	{
		matrix1[i] = malloc (sizeof (int) * m1);
		for (int j = 0; j < m1; j++)
			scanf("%d", &matrix1[i][j]);
	}
	
	int n2, m2;
	scanf ("%d %d", &n2, &m2);

	int **matrix2 = malloc (sizeof (int *) * n2);
	for (int i = 0; i < n2; i++)
	{
		matrix2[i] = malloc (sizeof (int) * m2);
		for (int j = 0; j < m2; j++)
			scanf("%d", &matrix2[i][j]);
	}

	if (m1 != n2)
		return 1;

	int **result = malloc (sizeof (int *) * n1);
	for (int i = 0; i < n1; i++)
	{
		result[i] = malloc (sizeof (int) * m2);
		for (int j = 0; j < m2; j++)
			result[i][j] = 0;
	}

	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m2; j++)
			for (int k = 0; k < m1; k++)
				result[i][j] += matrix1[i][k] * matrix2[k][j];

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
			printf ("%d ", result[i][j]);
		printf ("\n");
	}

	int **tmp = matrix1;
	int tmpn = n1;
	int tmpm = m1;

	matrix1 = matrix2;
	n1 = n2;
	m1 = m2;

	matrix2 = tmp;
	n2 = tmpn;
	m2 = tmpm;
	
	if (m1 != n2)
		return 1;

	int **result2 = malloc (sizeof (int *) * n1);
	for (int i = 0; i < n1; i++)
	{
		result2[i] = malloc (sizeof (int) * m2);
		for (int j = 0; j < m2; j++)
			result2[i][j] = 0;
	}

	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m2; j++)
			for (int k = 0; k < m1; k++)
				result2[i][j] += matrix1[i][k] * matrix2[k][j];

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
			printf ("%d ", result2[i][j]);
		printf ("\n");
	}

	return 0;
}

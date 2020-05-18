#include "MatrixHelper.h"

Matrix* createIdentity(int n)
{
	Matrix* m = new Matrix(n, n);
	for(int i = 1; i <= n; i++)
	{
		m->setEntry(i, i, 1);
	}
	return m;	
}

Matrix* getTranspose(Matrix* m)
{
	Matrix* result = new Matrix(m->width, m->height);

	for(int i = 1; i <= result->height; i++)
	{
		for(int j = 1; j <= result->width; j++)
		{
			result->setEntry(i, j, m->getEntry(j, i));
		}
	}

	return result;
}


#pragma once

#include "Matrix.h"

//Returns a square n x n matrix with 1s down the diagonal. 
Matrix* createIdentity(int n)
{
	Matrix* m = new Matrix(n, n);
	for(int i = 1; i <= n; i++)
	{
		m->setEntry(i, i, 1);
	}
	return m;	
}



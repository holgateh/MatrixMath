#include "PMatrixHelper.h"
PMatrix PcreateIdentity(size_t n)
{
	PMatrix m = PMatrix(n, n);
	for(size_t i = 1; i <= n; i++)
	{
		m.setEntry(i, i, Polynomial({1}));
	}
	return m;	
}

PMatrix PgetTranspose(PMatrix m)
{
	PMatrix result = PMatrix(m.width, m.height);

	for(int i = 1; i <= result.height; i++)
	{
		for(int j = 1; j <= result.width; j++)
		{
			result.setEntry(i, j, m.getEntry(j, i));
		}
	}

	return result;
}

PMatrix convertMatrix(const Matrix<double>& m)
{

	PMatrix  result = PMatrix(m.height, m.width);

	for(size_t i = 1; i <= m.height; i++)
	{
		for(size_t j = 1; j <= m.width; j++)
		{
		    result.setEntry(i, j, Polynomial({m.getEntry(i,j)}));
		}
	}
	return result;
}


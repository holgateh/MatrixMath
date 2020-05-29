#include "PMatrixHelper.h"
PMatrix PcreateIdentity(int n)
{
	PMatrix m = PMatrix(n, n);
	for(int i = 1; i <= n; i++)
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

PMatrix convertMatrix(const Matrix& m)
{
	PMatrix result(m.height, m.width);

	for(int i = 1; i <= m.height; i++)
	{
		for(int j = 1; j <= m.width; j++)
		{
			result.setEntry(i, j, Polynomial({(float)m.getEntry(i,j)}));
		}
	}
	return result;
}


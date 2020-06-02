#include "MatrixHelper.h"
#include <iostream>
#include "PMatrix.h"
#include "PMatrixHelper.h"
#include "PolynomialHelper.h"

Matrix createIdentity(int n)
{
	Matrix m =  Matrix(n, n);
	for(int i = 1; i <= n; i++)
	{
		m.setEntry(i, i, 1);
	}
	return m;	
}

Matrix getTranspose(Matrix m)
{
	Matrix result =  Matrix(m.width, m.height);

	for(int i = 1; i <= result.height; i++)
	{
		for(int j = 1; j <= result.width; j++)
		{
			result.setEntry(i, j, m.getEntry(j, i));
		}
	}

	return result;
}

std::vector<double> getEigenValues(const Matrix& m)
{
	if(m.width != m.height)
	{
		std::cout << "Can only calculate eigenvalues of square matrices.\n";
		return std::vector<double> (0);
	}
	//Create Matrix M - X*I
	PMatrix detMatrix = convertMatrix(m) - Polynomial({0, -1}) * PcreateIdentity(m.height);
	//Calculate the determinant of the above matrix to get the characteristic polynomial.
	Polynomial characteristic = detMatrix.det();
	//return the roots of this equation: the eigenvalues of m
	return getRoots(characteristic); 
	
}


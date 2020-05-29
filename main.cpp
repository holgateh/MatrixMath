#include <iostream>
#include "stdlib.h"
#include "Matrix.h"
#include "MatrixHelper.h"
#include "Polynomial.h"
#include "PolynomialHelper.h"
#include <vector>
int main()
{
	Matrix m = 3.0f * createIdentity(3);
	m.setEntry(2,1, 12);
	m.printMatrix();
	std::vector<double> eValues = getEigenValues(m);
	for(int i = 0; i < eValues.size(); i++)
	{
		std::cout << eValues.at(i) << " ";
	}
	std::cout << std::endl;
	return 0;
}

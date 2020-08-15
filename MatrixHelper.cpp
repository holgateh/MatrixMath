#include "MatrixHelper.h"
#include "Polynomial.h"

std::vector<double> getEigenValues(const Matrix<double>& m)
{
	if(m.width != m.height)
	{
        throw std::runtime_error("Error: Can only caculate eigenvalues of square matrices.");
	}

	//Create Matrix M - X*I
    auto p = Polynomial({0, -1}) * PcreateIdentity(m.height);
	PMatrix detMatrix = convertMatrix(m) + Polynomial({-1})* p;
	//Calculate the determinant of the above matrix to get the characteristic polynomial.

    std::cout << "1\n";
	Polynomial characteristic = detMatrix.det();
	//return the roots of this equation: the eigenvalues of m
	return getRoots(characteristic); 
	
}


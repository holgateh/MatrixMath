#include "MatrixHelper.h"
#include "Polynomial.h"

std::vector<double> getEigenValues(const Matrix<double>& m)
{
	if(m.width != m.height)
	{
        throw std::runtime_error("Error: Can only caculate eigenvalues of square matrices.");
	}

	//Create Matrix M - X*I
    Matrix<Polynomial> p = Polynomial({0, -1}) * Matrix<Polynomial>::createIdentity(m.height);
	auto detMatrix = convertMatrix(m) + p;

	//Calculate the determinant of the above matrix to get the characteristic polynomial.

	Polynomial characteristic = detMatrix.det();
	//return the roots of this equation: the eigenvalues of m
    std::cout << "Characteristic: " << characteristic << "\n";
	return getRoots(characteristic); 
	
}

Matrix<Polynomial> convertMatrix(const Matrix<double>& m)
{

    auto result = Matrix<Polynomial>(m.height, m.width);

	for(size_t i = 1; i <= m.height; i++)
	{
		for(size_t j = 1; j <= m.width; j++)
		{
		    result.setEntry(i, j, Polynomial({m.getEntry(i,j)}));
		}
	}
	return result;
}

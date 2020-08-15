#include <iostream>
#include "stdlib.h"
#include "Matrix.h"
#include "MatrixHelper.h"
#include "Polynomial.h"
#include "PolynomialHelper.h"
#include <vector>

int main()
{
    Matrix<double> m = 3.0 * Matrix<double>::createIdentity(3);
    m.setEntry(2,1, 12);
    m.printMatrix();

    std::vector<int> v = {3, 2, 1};
    std::vector<double> eValues = getEigenValues(m);
    for(int i = 0; i < eValues.size(); i++)
    {
    std::cout << eValues.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}

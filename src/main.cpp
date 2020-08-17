#include <iostream>
#include <stdlib.h>
#include "../include/Matrix.hpp"
#include "../include/MatrixHelper.hpp"
#include "../include/Polynomial.hpp"
#include "../include/PolynomialHelper.hpp"
#include <vector>

int main()
{
    Matrix<double> m = 3.0 * Matrix<double>::createIdentity(3);
    m.printMatrix();
    std::vector<double> eValues = getEigenValues(m);
    std::cout << "Eigen values: ";
    for(int i = 0; i < eValues.size(); i++)
    {
        std::cout << eValues.at(i) << " ";
    }
    std::cout << "\n";
    return 0;
}

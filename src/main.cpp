#include <iostream>
#include <stdlib.h>
#include "../include/Matrix.hpp"
#include "../include/MatrixHelper.hpp"
#include "../include/Polynomial.hpp"
#include "../include/PolynomialHelper.hpp"
#include <vector>

int main()
{
    Timer t ("main loop timer");
    Matrix<double> m = 3.0 * Matrix<double>::createIdentity(3);
    Matrix<double> n = 2.0 * Matrix<double>::createIdentity(3);
    m.printMatrix();
    n.printMatrix();
    (m * n).printMatrix();


    std::vector<double> eigenValues = getEigenValues(m);
    std::vector<Matrix<double>> eigenVectors = getEigenVectors(eigenValues, m);
    std::cout << "Eigen values: ";
    for (uint32_t i = 0; i < eigenValues.size(); i++)
    {
        std::cout << "[" << i << "] = " << eigenValues.at(i) << " ";
    }
    std::cout << "\n";

    for (auto v : eigenVectors)
    {
        v.printMatrix();
        std::cout << "\n";
    }
    return 0;
}

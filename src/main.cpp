#include <iostream>
#include <stdlib.h>
#include "../include/Matrix.hpp"
#include "../include/MatrixHelper.hpp"
#include "../include/Polynomial.hpp"
#include "../include/PolynomialHelper.hpp"
#include <vector>

int main()
{
    Matrix<double> m = Matrix<double>::createIdentity(3);
    m.setEntry(1, 2, 1);
    m.setEntry(2, 3, 1);
    m.printMatrix();
    std::vector<double> eigenValues = getEigenValues(m);
    std::vector<Matrix<double>> eigenVectors = getEigenVectors(eigenValues, m);
    std::cout << "Eigen values: ";
    for (size_t i = 0; i < eigenValues.size(); i++)
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

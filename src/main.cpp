#include <iostream>
#include <stdlib.h>
#include "../include/Matrix.hpp"
#include "../include/MatrixHelper.hpp"
#include "../include/Polynomial.hpp"
#include "../include/PolynomialHelper.hpp"
#include <vector>

int main()
{
    Matrix<double> m = 3.0 * Matrix<double>(3, 3);
    m.setEntry(1, 1, 1);
    m.setEntry(2, 2, 3);
    m.setEntry(2, 3, 4);
    m.setEntry(3, 1, 11.0);
    m.printMatrix();
    std::vector<double> eigenValues = getEigenValues(m);
    std::vector<Matrix<double>> eVectors = getEigenVectors(eigenValues, m);
    std::cout << "Eigen values: ";
    for (size_t i = 0; i < eigenValues.size(); i++)
    {
        std::cout << "[" << i << "] = " << eigenValues.at(i) << " ";
    }
    std::cout << "\n";

    for (auto v : eVectors)
    {
        v.printMatrix();
        std::cout << "\n";
    }
    return 0;
}

#pragma once

#include "../include/Matrix.hpp"
#include "../include/PolynomialHelper.hpp"
#include <vector>
#include <iostream>

//Returns a square n x n matrix with 1s down the diagonal. 
std::vector<double> getEigenValues(const Matrix<double>& m);
Matrix<Polynomial> convertMatrix(const Matrix<double>& m);

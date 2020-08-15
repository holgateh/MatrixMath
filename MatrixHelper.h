#pragma once

#include "Matrix.h"
#include <vector>
#include <iostream>
#include "PMatrix.h"
#include "PMatrixHelper.h"
#include "PolynomialHelper.h"

//Returns a square n x n matrix with 1s down the diagonal. 
std::vector<double> getEigenValues(const Matrix<double>& m);


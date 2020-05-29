#pragma once

#include "Matrix.h"
#include <vector>

//Returns a square n x n matrix with 1s down the diagonal. 
Matrix createIdentity(int n);
Matrix getTranspose(Matrix m);
std::vector<double> getEigenValues(const Matrix& m);


#pragma once

#include "PMatrix.h"
#include "Matrix.h"

//Returns a square n x n matrix with 1s down the diagonal. 
PMatrix PcreateIdentity(size_t n);
PMatrix PgetTranspose(const PMatrix& m);
PMatrix convertMatrix(const Matrix<double>& m);

#pragma once

#include "PMatrix.h"
#include "Matrix.h"

//Returns a square n x n matrix with 1s down the diagonal. 
PMatrix PcreateIdentity(int n);
PMatrix PgetTranspose(PMatrix m);
PMatrix convertMatrix(const Matrix& m);

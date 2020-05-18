#pragma once

#include "Matrix.h"

//Returns a square n x n matrix with 1s down the diagonal. 
Matrix* createIdentity(int n);
Matrix* getTranspose(Matrix* m);

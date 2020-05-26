#pragma once
#include <vector>
#include "Polynomial.h"
int sign(float x);
float bisect(Polynomial p, float a, float b);
Polynomial reduce(Polynomial p, float root);
Polynomial makeMonic(Polynomial p);
std::vector<float> getRoots(Polynomial p);

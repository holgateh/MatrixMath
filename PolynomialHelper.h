#pragma once
#include <vector>
#include "Polynomial.h"
int sign(double x);
double bisect(Polynomial p, double a, double b);
Polynomial reduce(Polynomial p, double root);
Polynomial makeMonic(Polynomial p);
std::vector<double> getRoots(Polynomial p);

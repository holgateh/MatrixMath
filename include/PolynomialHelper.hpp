#pragma once
#include <vector>
#include "../include/Polynomial.hpp"
int sign(double x);
double bisect(Polynomial& p, double a, double b);
Polynomial reduce(Polynomial& p, double root);
Polynomial makeMonic(Polynomial& p);
std::vector<double> getRoots(Polynomial& p);

#include <iostream>
#include "stdlib.h"
#include "Matrix.h"
#include "MatrixHelper.h"
#include "Polynomial.h"
#include "PolynomialHelper.h"
#include <vector>
int main()
{
	Polynomial q = Polynomial({1, 1});
	Polynomial p = Polynomial({1, 1});
	p.printPolynomial();
	q.printPolynomial();
	Polynomial r = p * q;
	r.printPolynomial();
	return 0;
}

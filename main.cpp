#include <iostream>
#include "stdlib.h"
#include "Matrix.h"
#include "MatrixHelper.h"
#include "Polynomial.h"
#include "PolynomialHelper.h"
#include <vector>
int main()
{
	Polynomial p = Polynomial({-24, 26, -9, 1});
	p.printPolynomial();
	std::vector<float> roots = getRoots(p);	
	for(int i = 0; i < roots.size(); i++)
	{
		std::cout << roots.at(i) << " ";
	}
	std::cout << std::endl;	
	return 0;
}

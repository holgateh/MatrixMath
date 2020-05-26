#pragma once
#include <vector>
class Polynomial
{
    private:
	float order;
	std::vector<float> coeff;
    public:
        Polynomial(std::vector<float> coeff);
    private:

    public:
        void printPolynomial();
	float getOrder();
	float getCoefficient(int exponent);
	float evaluateAt(float x);
        
};

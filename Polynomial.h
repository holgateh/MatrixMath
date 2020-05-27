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
		float getOrder() const;
		float getCoefficient(int exponent) const;
		float evaluateAt(float x) const;
		void printPolynomial() const;
		// Operator overloads:
		friend Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator- (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator* (const Polynomial& p1, const Polynomial& p2);
};

Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
Polynomial operator- (const Polynomial& p1, const Polynomial& p2);
Polynomial operator* (const Polynomial& p1, const Polynomial& p2);

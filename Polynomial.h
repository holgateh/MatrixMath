#pragma once
#include <vector>
class Polynomial
{
    private:
		double order;
		std::vector<double> coeff;
    public:
		Polynomial(std::vector<double> coeff);
    private:

    public:
		double getOrder() const;
		double getCoefficient(int exponent) const;
		double evaluateAt(double x) const;
		void printPolynomial() const;
		double toFloat() const;
		// Operator overloads:
		friend Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator- (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator* (const Polynomial& p1, const Polynomial& p2);
};

Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
Polynomial operator- (const Polynomial& p1, const Polynomial& p2);
Polynomial operator* (const Polynomial& p1, const Polynomial& p2);

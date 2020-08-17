#pragma once
#include <vector>
#include <math.h>
#include <iostream>
class Polynomial
{
    private:
		double order;
		std::vector<double> coeff;
    public:
    private:

    public:
		Polynomial(std::vector<double> _coeff);
        Polynomial(double _coeff);
		double getOrder() const;
		double getCoefficient(size_t exponent) const;
		double evaluateAt(double x) const;
		double toFloat() const;
		// Operator overloads:
		friend Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator- (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator* (const Polynomial& p1, const Polynomial& p2);
        friend std::ostream& operator<< (std::ostream& os, const Polynomial& p);
        Polynomial& operator+= (const Polynomial& p)
        {
            *this = *this + p;
            return *this ; 

        }

        Polynomial& operator-= (const Polynomial& p)
        {
            *this = *this - p;
            return *this ; 

        }
        
        Polynomial& operator*= (const Polynomial& p)
        {
            *this = *this * p;
            return *this ; 

        }
};

Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
Polynomial operator- (const Polynomial& p1, const Polynomial& p2);
Polynomial operator* (const Polynomial& p1, const Polynomial& p2);
Polynomial operator+= (const Polynomial& p1, const Polynomial& p2);
std::ostream& operator<< (std::ostream& os, const Polynomial& p);
 




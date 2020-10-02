#pragma once
#include <vector>
#include <math.h>
#include <iostream>
class Polynomial
{
    private:
		double order;
    public:
		std::vector<double> coeff;
    private:

    public:
		Polynomial(std::vector<double> _coeff);
        Polynomial(const Polynomial& p);
        Polynomial(Polynomial&& p);
        Polynomial(double _coeff);
		double getOrder() const;
		double getCoefficient(uint32_t exponent) const;
		double evaluateAt(double x) const;
		double toFloat() const;
		// Operator overloads:
		friend Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator- (const Polynomial& p1, const Polynomial& p2);
		friend Polynomial operator* (const Polynomial& p1, const Polynomial& p2);
        friend std::ostream& operator<< (std::ostream& os, const Polynomial& p);

        Polynomial& operator= (const Polynomial& p)
        {
            coeff = p.coeff; 
            order = coeff.size() - 1;// recalculate order.
            return *this;
        }

        Polynomial& operator= (Polynomial&& p)
        {
            coeff = std::move(p.coeff);
            order = coeff.size() - 1;// recalculate order.
            p.coeff = {};
            return *this;

        }

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
 




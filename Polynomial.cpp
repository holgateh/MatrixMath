#include "Polynomial.h"
#include <math.h>
#include <iostream>

Polynomial::Polynomial(const std::vector<double> _coeff)
{
    coeff = _coeff;
    order = coeff.size() - 1;
}


double Polynomial::getOrder() const
{
    return order;
}

double Polynomial::getCoefficient(int exponent) const
{
    if(exponent < 0 || exponent > order)
    {
        throw std::runtime_error("Exponenet must be in range");
    }
    else
    {
        return coeff.at(exponent);
    }
}


double Polynomial::evaluateAt(double x) const
{
    double result = 0;
    for(int i = 0; i <= order; i++)
    {
        result += coeff.at(i) * pow(x, i);
    }
    return result; 
}

void Polynomial::printPolynomial() const
{
    for(int i = 0; i <= order; i++)
    {
        std::cout << coeff.at(i) << "X^" << i;
        if(i != order)
        {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;

}
double Polynomial::toFloat() const
{
    if(order > 0)
    {
        throw std::runtime_error("Exponenet must be in range");
    }
    return coeff.at(0); 
}

Polynomial operator+ (const Polynomial& p1, const Polynomial& p2)
{
    std::vector<double> newCoeff;
    if(p1.getOrder() >= p2.getOrder())
    {
        for(int i = 0; i <= p1.getOrder(); i++)
        {
            if(i <= p2.getOrder())
            {
                newCoeff.push_back(p1.getCoefficient(i) + p2.getCoefficient(i));
            }
            else
            {
                newCoeff.push_back(p1.getCoefficient(i));
            }
        }
    }
    else
    {
        for(int i = 0; i <= p2.getOrder(); i++)
        {
            if(i <= p1.getOrder())
            {
                newCoeff.push_back(p2.getCoefficient(i) + p1.getCoefficient(i));
            }
            else
            {
                newCoeff.push_back(p2.getCoefficient(i));
            }
        }
    }
    return Polynomial(newCoeff);
}

Polynomial operator* (const Polynomial& p1, const Polynomial& p2)
{
    std::vector<double> newCoeff;
    for(int i = 0; i <= p1.getOrder() + p2.getOrder(); i++)
    {
        int coeff = 0;
        for(int j = 0; j <= i; j++)
        {
            if(j <= p1.getOrder() && i - j <= p2.getOrder())
            {
                coeff += p1.getCoefficient(j) * p2.getCoefficient(i-j);
            }
        }
        newCoeff.push_back(coeff);
    }
    return Polynomial(newCoeff);
}

Polynomial operator- (const Polynomial& p1, const Polynomial& p2)
{
    return p1 + (Polynomial({-1}) * p2); 
}

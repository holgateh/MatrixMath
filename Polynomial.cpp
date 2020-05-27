#include "Polynomial.h"
#include <math.h>
#include <iostream>

Polynomial::Polynomial(const std::vector<float> coeff)
{
	this->coeff = coeff;
	this->order = coeff.size() - 1;
}


float Polynomial::getOrder() const
{
	return this->order;
}

float Polynomial::getCoefficient(int exponent) const
{
	if(exponent < 0 || exponent > this->order)
	{
		std::cout << "Error: exponent out of bounds. -1 will be returned. Please enter a value between x | 0 <= x <= [Order of Polynomial].\n";
		return -1;
	}
	else
	{
		return coeff.at(exponent);
	}
}


float Polynomial::evaluateAt(float x) const
{
	float result = 0;
	for(int i = 0; i <= this->order; i++)
	{
		result += coeff.at(i) * pow(x, i);
	}
	return result;	
}

void Polynomial::printPolynomial() const
{
	for(int i = 0; i <= this->order; i++)
	{
		std::cout << coeff.at(i) << "X^" << i;
		if(i != order)
		{
			std::cout << " + ";
		}
	}
	std::cout << std::endl;

}

Polynomial operator+ (const Polynomial& p1, const Polynomial& p2)
{
	std::vector<float> newCoeff;
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
	std::vector<float> newCoeff;
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

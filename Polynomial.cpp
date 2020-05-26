#include "Polynomial.h"
#include <math.h>
#include <iostream>

Polynomial::Polynomial(const std::vector<float> coeff)
{
	this->coeff = coeff;
	this->order = coeff.size() - 1;
}

void Polynomial::printPolynomial()
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

float Polynomial::getOrder()
{
	return this->order;
}

float Polynomial::getCoefficient(int exponent)
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


float Polynomial::evaluateAt(float x)
{
	float result = 0;
	for(int i = 0; i <= this->order; i++)
	{
		result += coeff.at(i) * pow(x, i);
	}
	return result;	
}


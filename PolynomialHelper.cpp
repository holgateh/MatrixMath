#include "Polynomial.h"
#include <iostream>
#include <math.h>
#include <cfloat>

int sign(float x)
{
	return x / abs(x);
}

float bisect(Polynomial p, float a, float b)
{
	int N = 1;
	const int maxN = 10000;
	const float tol = 0.00005f;
	float c;
	while(N <= maxN)
	{	
		c = (a + b) / 2.0f;	

		if(abs(p.evaluateAt(c)) < tol)
		{
			break;
		}
		
		N++;

		if(sign(p.evaluateAt(c)) == sign(p.evaluateAt(a)))
		{
			a = c;
		}
		else
		{
			b = c;
		}

	}

	if(N == maxN)
	{
		return FLT_MAX;
	}
	else
	{
		return c;
	}
}


Polynomial reduce(Polynomial p, float root)
{
	std::vector<float> newCoeff;
	for(int i = p.getOrder() - 1; i >= 0; i--)
	{
		float coeff;
		if(i == p.getOrder() - 1)
		{
			coeff = p.getCoefficient(i + 1);
		}	
		else
		{
			coeff = p.getCoefficient(i + 1) +  root * newCoeff.at(0);
		}
		newCoeff.insert(newCoeff.begin(), coeff);
	}
	return Polynomial(newCoeff);
}

Polynomial makeMonic(Polynomial p)
{
	std::vector<float> newCoeff;
	for(int i = 0; i <= p.getOrder(); i++)
	{
		newCoeff.push_back(p.getCoefficient(i)/p.getCoefficient(p.getOrder()));
	}
	Polynomial result = Polynomial(newCoeff);
	return result;
}

std::vector<float> getRoots(Polynomial p)
{
	std::vector<float> roots;
	Polynomial tempPoly = p;	
	while(tempPoly.getOrder() >= 2)
	{
	
		if(tempPoly.getOrder() > 2)
		{
			tempPoly = makeMonic(tempPoly);
			float root = bisect(tempPoly, -abs(tempPoly.getCoefficient(0)) - 1, abs(tempPoly.getCoefficient(0)) + 1);

			if(root != FLT_MAX)
			{	
				roots.push_back(root);
				tempPoly = reduce(tempPoly, root);
				tempPoly.printPolynomial();
			}
			else
			{
				std::cout << "Bisection algorithm failed -- Could not find any roots.\n";
				break;
			}
		}
		else if(tempPoly.getOrder() == 2)
		{
			float a = tempPoly.getCoefficient(2);
			float b = tempPoly.getCoefficient(1);
			float c = tempPoly.getCoefficient(0);

			if(b*b - 4*a*c < 0)
			{
				std::cout << "No real roots found.";
				break;
			}
			else
			{
				float root1, root2;
				root1 = (-b + sqrt(b*b - 4.0f * a * c)) / (2.0f * a);
				root2 = (-b - sqrt(b*b - 4.0f * a * c)) / (2.0f * a);
				roots.push_back(root1);
				roots.push_back(root2);
				break;
			}
		}
		else if(tempPoly.getOrder() == 1)
		{
			roots.push_back(-tempPoly.getCoefficient(0)/tempPoly.getCoefficient(1));
			break;
		}
		else if(tempPoly.getOrder() == 0)
		{
			if(tempPoly.getCoefficient(0) == 0)
			{
				roots.push_back(0);
			}
			else
			{
				std::cout << "No roots could be found. The only constant polynomial that has a root is the zero polynomial.\n";
			}
			break;
		}

	}
	return roots;

} 



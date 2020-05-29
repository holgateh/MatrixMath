#include "PMatrix.h"
#include <iostream>
#include <string.h>
#include <math.h>
//Set the width and height of the matrix and allocate memory to store the matrix's data.
PMatrix::PMatrix(int _height, int _width) : height(_height), width(_width) 
{
	//Fill the matrix with the zero polynomial.
	for(int i = 0; i < _height; i++)
	{
		for(int j = 0; j < _width; j++)
		{
			data.push_back(Polynomial({0}));	
		}
	}
}

void PMatrix::setEntry(int i, int j, Polynomial value)
{
	if(i < 1 || j < 1 || i > height || j > width)
	{
		std::cout << "Cannot set entry due to position being out of bounds.\n";
		return;
	}
	this->data[(i-1)*this->width + (j-1)] = value;
}

Polynomial PMatrix::getEntry(int i, int j) const
{
	return data[(i-1)*this->width + (j-1)];
}

PMatrix PMatrix::getSubmatrix(int i, int j)
{
	PMatrix result = PMatrix(this->width - 1, this->height - 1);
	//Keeping track of the index that we are writing to in the resultant submatrix.	
	int workingIndexX = 1;
	int workingIndexY = 1;
	for(int k = 1; k <= this->height; k++)
	{
		if(k != i)
		{
			for(int l = 1; l <= this->width; l++)
			{
				if(l != j)
				{
					result.setEntry(workingIndexY, workingIndexX, this->getEntry(k, l));
					workingIndexX++;
				}
			}
			workingIndexX = 1;
			workingIndexY++;
		}
	}	
	
	return result;
}

Polynomial PMatrix::det()
{
	//Return if the matrix is not square.
	if(this->width != this->height)
	{
		std::cout << "Determinants of non-square matrices cannot be calculated. -1 will be returned.\n";
		return Polynomial({-1});
	}
	//Return the only entry if the matrix is 1x1.	
	if(this->height == 1)
	{
		this->getEntry(1,1);
	}

	//Recursivly call the algorithm until the 2x2 case is reached.
	if(this->height > 2)
	{
		Polynomial sum({0}); 
		for(int i = 1; i <= this->height; i++)
		{
			PMatrix subPMatrix = this->getSubmatrix(i,1);
			sum = sum + Polynomial({(double)pow(-1, i+1)}) * this->getEntry(i, 1) * subPMatrix.det();
		}
		return sum;	
	}
	//Base case of the recursion: the 2x2 case.
	else
	{
		return this->getEntry(1,1) * this->getEntry(2,2) - this->getEntry(2,1) * this->getEntry(1,2); 
	}
	
}

void PMatrix::printPMatrix()
{
	for(int i = 1; i <= this->height; i++)
	{
		for(int j = 1; j <= this->width; j++)
		{
			std::cout << "(" << i << ", " << j << "): ";
			this->getEntry(i,j).printPolynomial();
			std::cout << std::endl;
		}
	}	
}
PMatrix operator+ (const PMatrix& m1, const PMatrix& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height && m1.width != m2.width)
	{
		std::cout << "Error: + operator failed due matrices being of different dimension.\n";
		return PMatrix(0,0);
	}
	PMatrix result =  PMatrix(m1.height, m1.width);

	for(int i = 1; i <= m1.height; i++)
	{
		for(int j = 1; j <= m1.width; j++)
		{
			result.setEntry(i, j, m1.getEntry(i,j) + m2.getEntry(i,j));
		}
	}

	return result;
}

PMatrix operator- (const PMatrix& m1, const PMatrix& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height && m1.width != m2.width)
	{
		std::cout << "Error: + operator failed due matrices being of different dimension.\n";
		return PMatrix(0,0);
	}
	PMatrix result = PMatrix(m1.height, m1.width);

	for(int i = 1; i <= m1.height; i++)
	{
		for(int j = 1; j <= m1.width; j++)
		{
			result.setEntry(i, j, m1.getEntry(i,j) + m2.getEntry(i,j));
		}
	}

	return result;
}



PMatrix operator* (const PMatrix& m1, const PMatrix& m2)
{
	// The first matrix must have a witdh equal to the height of the second matrix in order for valid multiplication.
	if(m1.width != m2.height)
	{
		std::cout << "Error: * operator failed due to first matrix having a width not equal to the height of the second matrix.\n";
		return PMatrix(0,0);
	}
	PMatrix result =  PMatrix(m1.height, m2.width);

	for(int i = 1; i <= m1.height; i++)
	{
		for(int j = 1; j <= m2.width; j++)
		{
			Polynomial resultantEntry({0});
			for(int k = 1; k <= m2.width; k++)
			{
				resultantEntry = resultantEntry +  m1.getEntry(i, k) * m2.getEntry(k, j);
			}
			result.setEntry(i, j, resultantEntry);
		}
	}

	return result;
	
}


PMatrix operator* (const Polynomial& p, const PMatrix& m)
{
	PMatrix result =  PMatrix(m.height, m.width);

	for(int i = 1; i <= m.height; i++)
	{
		for(int j = 1; j <= m.width; j++)
		{
			result.setEntry(i, j, p*m.getEntry(i,j));
		}
	}

	return result;
}

PMatrix operator* (const PMatrix& m, const Polynomial& p)
{
	return p * m;
}

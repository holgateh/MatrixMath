#include "PMatrix.h"
#include "Polynomial.h"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <math.h>
//Set the width and height of the matrix and allocate memory to store the matrix's data.
PMatrix::PMatrix(size_t _height, size_t _width) : height(_height), width(_width) 
{
    data = std::vector<Polynomial>();
    for (size_t i = 1; i <= height; i++)
    {
        for (size_t j = 1; j <= width; j++)
        {
            data.push_back(Polynomial({0}));
        }
    }
}

void PMatrix::setEntry(size_t i, size_t j, Polynomial value)
{
	if(i < 1 || j < 1 || i > height || j > width)
	{
        throw std::runtime_error("Matrix element index is out of bounds.");
	}
	data.at((i-1)*width + (j-1)) = value;
}

Polynomial PMatrix::getEntry(size_t i, size_t j) const 
{
	if(i < 1 || j < 1 || i > height || j > width)
	{
        throw std::runtime_error("Matrix element index is out of bounds.");
	}
	return data.at((i-1)*width + (j-1));
}

PMatrix PMatrix::getSubmatrix(size_t i, size_t j) 
{
	PMatrix result = PMatrix(width - 1, height - 1);
	//Keeping track of the index that we are writing to in the resultant submatrix.	
	size_t workingIndexX = 1;
	size_t workingIndexY = 1;
	for(size_t k = 1; k <= height; k++)
	{
		if(k != i)
		{
			for(size_t l = 1; l <= width; l++)
			{
				if(l != j)
				{
					result.setEntry(workingIndexY, workingIndexX, getEntry(k, l));
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
	if(width != height)
	{
        throw std::runtime_error("Determinants of non-square matrices cannot be calculated");
	}
	//Return the only entry if the matrix is 1x1.	
	if(height == 1)
	{
		getEntry(1,1);
	}

	//Recursivly call the algorithm until the 2x2 case is reached.
	if(height > 2)
	{
		Polynomial sum = Polynomial({0}); 
		for(size_t i = 1; i <= height; i++)
		{
			PMatrix subPMatrix = getSubmatrix(i,1);
			sum = sum + Polynomial({(double)pow(-1, i+1)}) * getEntry(i, 1) * subPMatrix.det();
		}
		return sum;	
	}
	//Base case of the recursion: the 2x2 case.
	else
	{
		return getEntry(1,1) * getEntry(2,2) - getEntry(2,1) * getEntry(1,2); 
	}
	
}

void PMatrix::printPMatrix() const
{
	for(size_t i = 1; i <= height; i++)
	{
		for(size_t j = 1; j <= width; j++)
		{
			std::cout << "(" << i << ", " << j << "): ";
			getEntry(i,j).printPolynomial();
			std::cout << std::endl;
		}
	}	
}
PMatrix operator+ (const PMatrix& m1, const PMatrix& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height || m1.width != m2.width)
	{
        throw std::runtime_error("Matrices must have compatible dimension.");
	}
	PMatrix result =  PMatrix(m1.height, m1.width);

	for(size_t i = 1; i <= m1.height; i++)
	{
		for(size_t j = 1; j <= m1.width; j++)
		{
			result.setEntry(i, j, m1.getEntry(i,j) + m2.getEntry(i,j));
		}
	}

	return result;
}

PMatrix operator- (const PMatrix& m1, const PMatrix& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height || m1.width != m2.width)
	{
        throw std::runtime_error("Matrices must have compatible dimension.");
	}
	PMatrix result = PMatrix(m1.height, m1.width);
    std::cout << result.height << " " <<  result.width << "\n";

	for(size_t i = 1; i <= m1.height; i++)
	{
		for(size_t j = 1; j <= m1.width; j++)
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
        throw std::runtime_error("Matrices must have compatible dimension.");
	}
	PMatrix result =  PMatrix(m1.height, m2.width);

	for(size_t i = 1; i <= m1.height; i++)
	{
		for(size_t j = 1; j <= m2.width; j++)
		{
			Polynomial resultantEntry({0});
			for(size_t k = 1; k <= m2.width; k++)
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

	for(size_t i = 1; i <= m.height; i++)
	{
		for(size_t j = 1; j <= m.width; j++)
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

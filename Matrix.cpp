#include "Matrix.h"
#include <iostream>
#include <string.h>
#include <math.h>
//Set the width and height of the matrix and allocate memory to store the matrix's data.
Matrix::Matrix(int _height, int _width) : height(_height), width(_width) 
{
	this->data = (float *)malloc(sizeof(float) * this->width * this->height);
}

Matrix::~Matrix()
{
	//Free the memory allocated to data.
	free(data);
}

void Matrix::setEntry(int i, int j, float value)
{
	if(i < 1 || j < 1 || i > height || j > width)
	{
		std::cout << "Cannot set entry due to position being out of bounds.\n";
		return;
	}
	this->data[(i-1)*this->width + (j-1)] = value;
}

float Matrix::getEntry(int i, int j) const
{
	return data[(i-1)*this->width + (j-1)];
}

Matrix* Matrix::getSubmatrix(int i, int j)
{
	Matrix* result = new Matrix(this->width - 1, this->height - 1);
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
					result->setEntry(workingIndexY, workingIndexX, this->getEntry(k, l));
					workingIndexX++;
				}
			}
			workingIndexX = 1;
			workingIndexY++;
		}
	}	
	
	return result;
}

float Matrix::det()
{
	//Return if the matrix is not square.
	if(this->width != this->height)
	{
		std::cout << "Determinants of non-square matrices cannot be calculated. -1 will be returned.\n";
		return -1;
	}
	//Return the only entry if the matrix is 1x1.	
	if(this->height == 1)
	{
		return this->getEntry(1,1);
	}

	//Recursivly call the algorithm until the 2x2 case is reached.
	if(this->height > 2)
	{
		float sum = 0;
		for(int i = 1; i <= this->height; i++)
		{
			Matrix* subMatrix = this->getSubmatrix(i,1);
			sum += pow(-1, i+1) * this->getEntry(i, 1) * subMatrix->det();
			subMatrix->~Matrix();
			free(subMatrix);	
		}
		return sum;	
	}
	//Base case of the recursion: the 2x2 case.
	else
	{
		return this->getEntry(1,1) * this->getEntry(2,2) - this->getEntry(2,1) * this->getEntry(1,2); 
	}
	
}

void Matrix::printMatrix()
{
	for(int i = 0; i < this->height; i++)
	{
		for(int j = 0; j < this->width; j++)
		{
			std::cout << std::to_string(data[i*this->width + j]).substr(0, 4) << " ";	
		}
		std::cout << std::endl;
	}	
}

Matrix* operator+ (const Matrix& m1, const Matrix& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height && m1.width != m2.width)
	{
		std::cout << "Error: + operator failed due matrices being of different dimension.\n";
		return nullptr;
	}
	Matrix* result = new Matrix(m1.height, m1.width);

	for(int i = 1; i <= m1.height; i++)
	{
		for(int j = 1; j <= m1.width; j++)
		{
			result->setEntry(i, j, m1.getEntry(i,j) + m2.getEntry(i,j));
		}
	}

	return result;
}

Matrix* operator- (const Matrix& m1, const Matrix& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height && m1.width != m2.width)
	{
		std::cout << "Error: + operator failed due matrices being of different dimension.\n";
		return nullptr;
	}
	Matrix* result = new Matrix(m1.height, m1.width);

	for(int i = 1; i <= m1.height; i++)
	{
		for(int j = 1; j <= m1.width; j++)
		{
			result->setEntry(i, j, m1.getEntry(i,j) + m2.getEntry(i,j));
		}
	}

	return result;
}



Matrix* operator* (const Matrix& m1, const Matrix& m2)
{
	// The first matrix must have a witdh equal to the height of the second matrix in order for valid multiplication.
	if(m1.width != m2.height)
	{
		std::cout << "Error: * operator failed due to first matrix having a width not equal to the height of the second matrix.\n";
		return nullptr;
	}
	Matrix* result = new Matrix(m1.height, m2.width);

	for(int i = 1; i <= m1.height; i++)
	{
		for(int j = 1; j <= m2.width; j++)
		{
			float resultantEntry = 0;
			for(int k = 1; k <= m2.width; k++)
			{
				resultantEntry += m1.getEntry(i, k) * m2.getEntry(k, j);
			}
			result->setEntry(i, j, resultantEntry);
		}
	}

	return result;
	
}


Matrix* operator* (const float& s, const Matrix& m)
{
	Matrix* result = new Matrix(m.height, m.width);

	for(int i = 1; i <= m.height; i++)
	{
		for(int j = 1; j <= m.width; j++)
		{
			result->setEntry(i, j, s*m.getEntry(i,j));
		}
	}

	return result;
}

Matrix* operator* (const Matrix& m, const float& s)
{
	return s * m;
}

#include "Matrix.h"
#include <iostream>
#include <string.h>
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

void Matrix::printMatrix()
{
	std::cout << "This is a test... printing matrix\n";	
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




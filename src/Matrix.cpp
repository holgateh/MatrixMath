#include "../include/Matrix.hpp"

//Set the width and height of the matrix and allocate memory to store the matrix's data.
template <class T>
Matrix<T>::Matrix(uint32_t _height, uint32_t _width) : height(_height), width(_width) 
{
    data = std::vector<T>(height * width, (T)0); 
}	

template <class T>
Matrix<T>::Matrix(const Matrix<T>& m) : height(m.height), width(m.width)
{
    data = m.data;
}

template <class T>
Matrix<T>::Matrix(Matrix<T>&& m) : height(m.height), width(m.width)  
{
    data = std::move(m.data);
    m.data = {};
}

template <class T>
void Matrix<T>::setEntry(uint32_t i, uint32_t j, T value) 
{
	if(i < 1 || j < 1 || i > height || j > width)
	{
		std::cout << "Cannot set entry due to position being out of bounds.\n";
		return;
	}
	data[(i-1)*width + (j-1)] = value;
}
template <class T>
T Matrix<T>::getEntry(uint32_t i, uint32_t j) const
{
	return data[(i-1)*width + (j-1)];
}

template <class T>
Matrix<T> Matrix<T>::getSubmatrix(uint32_t i, uint32_t j) const 
{
	auto result =  Matrix(width - 1, height - 1);
	//Keeping track of the index that we are writing to in the resultant submatrix.	
	uint32_t workingIndexX = 1;
	uint32_t workingIndexY = 1;
	for(uint32_t k = 1; k <= height; k++)
	{
		if(k != i)
		{
			for(uint32_t l = 1; l <= width; l++)
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

template <class T>
T Matrix<T>::det() const
{
	//Return if the matrix is not square.
	if(width != height)
	{
        throw std::runtime_error("Cannot compute determinant of non square matrices.");
	}
	//Return the only entry if the matrix is 1x1.	
	if(height == 1)
	{
		return getEntry(1,1);
	}

	//Recursivly call the algorithm until the 2x2 case is reached.
	if(height > 2)
	{
		T sum = 0;
		for(uint32_t i = 1; i <= height; i++)
		{
			auto subMatrix = getSubmatrix(i,1);
			sum += pow(-1, i+1) * getEntry(i, 1) * subMatrix.det();
		}
		return sum;	
	}
	//Base case of the recursion: the 2x2 case.
	else
	{
		return getEntry(1,1) * getEntry(2,2) - getEntry(2,1) * getEntry(1,2); 
	}
	
}

template <class T>
void Matrix<T>::printMatrix() const
{
	for(uint32_t i = 0; i < height; i++)
	{
		for(uint32_t j = 0; j < width; j++)
		{
			std::cout << data[i*width + j] << " ";	
		}
		std::cout << std::endl;
	}	
}


template <class T>
Matrix<T> Matrix<T>::createIdentity(uint32_t n)
{
	Matrix<T> m =  Matrix<T>(n, n);
	for(uint32_t i = 1; i <= n; i++)
	{
		m.setEntry(i, i, T(1.0));
	}
	return m;	
}

template <class T>
Matrix<T> Matrix<T>::getTranspose() const
{
	Matrix<T> result =  Matrix<T>(width, height);

	for(uint32_t i = 1; i <= result.height; i++)
	{
		for(uint32_t j = 1; j <= result.width; j++)
		{
			result.setEntry(i, j, getEntry(j, i));
		}
	}

	return result;
}


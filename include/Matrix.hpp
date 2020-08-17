#pragma once
#include "../include/Polynomial.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <math.h>
template <class T>
class Matrix;


template <class T>
class Matrix
{
	private:
		std::vector<T> data;
	public:
		const size_t height, width;
	private:
	public:
		Matrix(size_t _height, size_t _width);
		void setEntry(size_t i, size_t j, T value);
		T getEntry(size_t i, size_t j) const;
		Matrix<T>getSubmatrix(size_t i, size_t j) const;
		T det() const;
		void printMatrix() const;


        Matrix<T> getTranspose() const;
        static Matrix<T> createIdentity(size_t n);
		// Operator overloads:

        template<class U>
        friend Matrix<U> operator+ (const Matrix<U>& m1, const Matrix<U>& m2);
        template<class U>
        friend Matrix<U> operator- (const Matrix<U>& m1, const Matrix<U>& m2);
        template<class U>
        friend Matrix<U> operator* (const Matrix<U>& m1, const Matrix<U>& m2);
        template<class U>
        friend Matrix<U> operator* (const  U& s, const Matrix<U>& m);
        template<class U>
        friend Matrix<U> operator* (const Matrix<U>& m, const  U& s);
};

template <class U>
Matrix<U> operator+ (const Matrix<U>& m1, const Matrix<U>& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height && m1.width != m2.width)
	{
        throw std::runtime_error("Matrices must have compatible dimension.");
	}
	Matrix<U> result =  Matrix<U>(m1.height, m1.width);

	for(size_t i = 1; i <= m1.height; i++)
	{
		for(size_t j = 1; j <= m1.width; j++)
		{
			result.setEntry(i, j, m1.getEntry(i,j) + m2.getEntry(i,j));
		}
	}
	return result;
}

template <class U>
Matrix<U> operator- (const Matrix<U>& m1, const Matrix<U>& m2)
{
	// Matrices that are to be added must have equal dimension;
	if(m1.height != m2.height && m1.width != m2.width)
	{
        throw std::runtime_error("Matrices must have compatible dimension.");
	}
	Matrix<U> result =  Matrix<U>(m1.height, m1.width);

	for(size_t i = 1; i <= m1.height; i++)
	{
		for(size_t j = 1; j <= m1.width; j++)
		{
			result.setEntry(i, j, m1.getEntry(i,j) + m2.getEntry(i,j));
		}
	}

	return result;
}


template <class U>
Matrix<U> operator* (const Matrix<U>& m1, const Matrix<U>& m2)
{
    Matrix<U> result =  Matrix<U>(m1.height, m2.width);
	// Uhe first matrix must have a witdh equal to the height of the second matrix in order for valid multiplication.
	if(m1.width != m2.height)
	{
        throw std::runtime_error("Matrices must have compatible dimension.");
	}

	for(size_t i = 1; i <= m1.height; i++)
	{
		for(size_t j = 1; j <= m2.width; j++)
		{
			double resultantEntry = 0;
			for(size_t k = 1; k <= m2.width; k++)
			{
				resultantEntry += m1.getEntry(i, k) * m2.getEntry(k, j);
			}
			result.setEntry(i, j, resultantEntry);
		}
	}
	return result;
}

template <class U>
Matrix<U> operator* (const U& s, const Matrix<U>& m)
{
	Matrix<U> result =  Matrix<U>(m.height, m.width);

	for(size_t i = 1; i <= m.height; i++)
	{
		for(size_t j = 1; j <= m.width; j++)
		{
			result.setEntry(i, j, s*m.getEntry(i,j));
		}
	}

	return result;
}

template <class U>
Matrix<U> operator* (const Matrix<U>& m, const U& s)
{
	return s * m;
}


template class Matrix<Polynomial>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<int>;


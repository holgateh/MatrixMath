#pragma once
#include "../include/Polynomial.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <math.h>
#include <thread>
#include <functional>
#include <mutex>
#include <algorithm>

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
        Matrix(const Matrix<T>& m);
        Matrix(Matrix<T>&& m);
		void setEntry(size_t i, size_t j, T value);
		T getEntry(size_t i, size_t j) const;
		Matrix<T>getSubmatrix(size_t i, size_t j) const;
		T det() const;
		void printMatrix() const;


        Matrix<T> getTranspose() const;
        static Matrix<T> createIdentity(size_t n);
		// Operator overloads:

        Matrix<T>& operator= (Matrix<T>&& m)
        {
            *this = Matrix<T>(m);
            return *this; 
        }

        Matrix<T>& operator= (const Matrix<T>& m)
        {
            data = m.data; 
            return *this;
        }

        template <class U>
        friend Matrix<U> operator+ (const Matrix<U>& m1, const Matrix<U>& m2);
        template <class U>
        friend Matrix<U> operator- (const Matrix<U>& m1, const Matrix<U>& m2);
        template<class U>
        friend Matrix<U> operator* (const Matrix<U>& m1, const Matrix<U>& m2);
        template <class U>
        friend Matrix<U> operator* (const  U& s, const Matrix<U>& m);
        template <class U>
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


    const size_t nloop = result.height * result.width;
    const size_t nthreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads(nthreads);
    std::mutex critical;

    auto add =  [&](const size_t bi, const size_t ei, const size_t t)
            {
                for(size_t i = bi; i < ei; i++)
                {   
                    result.data[i] = m1.data[i] + m2.data[i]; 
                }
            };
    for (size_t t = 0; t < nthreads; t++)
    {
        threads[t] = std::thread(std::bind(
           add, t*nloop/nthreads, (t+1) == nthreads ? nloop:(t+1)*nloop/nthreads,t));
    }

    std::for_each(threads.begin(), threads.end(), [](std::thread& x){x.join();});

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

    const size_t nloop = result.height * result.width;
    const size_t nthreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads(nthreads);
    std::mutex critical;

    auto sub =  [&](const size_t bi, const size_t ei, const size_t t)
            {
                for(size_t i = bi; i < ei; i++)
                {   
                    result.data[i] = m1.data[i] - m2.data[i]; 
                }
            };
    for (size_t t = 0; t < nthreads; t++)
    {
        threads[t] = std::thread(std::bind(
           sub, t*nloop/nthreads, (t+1) == nthreads ? nloop:(t+1)*nloop/nthreads,t));
    }

    std::for_each(threads.begin(), threads.end(), [](std::thread& x){x.join();});

	return result;
}


template <class U>
Matrix<U> operator* (const Matrix<U>& m1, const Matrix<U>& m2)
{
	// The first matrix must have a witdh equal to the height of the second matrix in order for valid multiplication.
	if(m1.width != m2.height)
	{
        throw std::runtime_error("Matrices must have compatible dimension.");
	}

    Matrix<U> result =  Matrix<U>(m1.height, m2.width);
    const size_t nloop = result.height * result.width;
    const size_t nthreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads(nthreads);
    std::mutex critical;

    auto multiply =  [&](const size_t bi, const size_t ei, const size_t t)
            {
                for(size_t i = bi; i < ei; i++)
                {   
                    for(size_t k = 0; k < m2.width; k++)
                    {
                        result.data[i] += m1.data[(i - (i % m2.width)) / m2.width * m1.width + k] * m2.data[k * m2.height + i % m2.width]; 
                    }

                }
            };
    for (size_t t = 0; t < nthreads; t++)
    {
        threads[t] = std::thread(std::bind(
           multiply, t*nloop/nthreads, (t+1) == nthreads ? nloop:(t+1)*nloop/nthreads,t));
    }

    std::for_each(threads.begin(), threads.end(), [](std::thread& x){x.join();});

	return result;
}

template <class U>
Matrix<U> operator* (const U& s, const Matrix<U>& m)
{
    Matrix<U> result = Matrix<U>(m.height, m.width);
    const size_t nloop = m.width * m.height;
    const size_t nthreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads(nthreads);
    std::mutex critical;

    auto scale =  [&](const size_t bi, const size_t ei, const size_t t)
            {
                for(size_t i = bi; i < ei; i++)
                {   
                    result.data[i] = s * m.data[i];
                }
            };
    for (size_t t = 0; t < nthreads; t++)
    {
        threads[t] = std::thread(std::bind(
           scale, t*nloop/nthreads, (t+1) == nthreads ? nloop:(t+1)*nloop/nthreads,t));
    }

    std::for_each(threads.begin(), threads.end(), [](std::thread& x){x.join();});
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


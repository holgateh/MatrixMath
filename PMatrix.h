#pragma once
#include "Polynomial.h"
#include <vector>
class PMatrix
{
	private:
		std::vector<Polynomial> data;
	public:
		const size_t height, width;
	private:
	
	public:
		PMatrix(size_t _height, size_t _width) ;
		void setEntry(size_t i, size_t j, Polynomial value);
		Polynomial getEntry(size_t i, size_t j) const;
		PMatrix getSubmatrix(size_t i, size_t j) ;
		Polynomial det() ;
		void printPMatrix() const;

		// Operator overloads:
		friend PMatrix operator+ (const PMatrix& m1, const PMatrix& m2);
		friend PMatrix operator- (const PMatrix& m1, const PMatrix& m2);
		friend PMatrix operator* (const PMatrix& m1, const PMatrix& m2);
		friend PMatrix operator* (const Polynomial& p, const PMatrix& m);
		friend PMatrix operator* (const PMatrix& m, const Polynomial& p);
};

PMatrix operator+ (const PMatrix& m1, const PMatrix& m2);
PMatrix operator- (const PMatrix& m1, const PMatrix& m2);
PMatrix operator* (const PMatrix& m1, const PMatrix& m2);
PMatrix operator* (const Polynomial& p, const PMatrix& m);
PMatrix operator* (const PMatrix& m, const Polynomial& p);

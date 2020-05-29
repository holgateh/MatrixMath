#pragma once
#include "Polynomial.h"
#include <vector>
class PMatrix
{
	private:
		std::vector<Polynomial> data;
	public:
		const int height, width;
	private:
	
	public:
		PMatrix(int _height, int _width) ;
		void setEntry(int i, int j, Polynomial value);
		Polynomial getEntry(int i, int j) const;
		PMatrix getSubmatrix(int i, int j);
		Polynomial det();
		void printPMatrix();

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

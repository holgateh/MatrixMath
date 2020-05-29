#pragma once
#include <vector>
class Matrix
{
	private:
		std::vector<double> data;
	public:
		const int height, width;
	private:
	
	public:
		Matrix(int _height, int _width) ;
		void setEntry(int i, int j, double value);
		double getEntry(int i, int j) const;
		Matrix getSubmatrix(int i, int j);
		double det();
		void printMatrix();

		// Operator overloads:
		friend Matrix operator+ (const Matrix& m1, const Matrix& m2);
		friend Matrix operator- (const Matrix& m1, const Matrix& m2);
		friend Matrix operator* (const Matrix& m1, const Matrix& m2);
		friend Matrix operator* (const double& s, const Matrix& m);
		friend Matrix operator* (const Matrix& m, const double& s);
};

Matrix operator+ (const Matrix& m1, const Matrix& m2);
Matrix operator- (const Matrix& m1, const Matrix& m2);
Matrix operator* (const Matrix& m1, const Matrix& m2);
Matrix operator* (const double& s, const Matrix& m);
Matrix operator* (const Matrix& m, const double& s);

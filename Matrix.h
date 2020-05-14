#pragma once
class Matrix
{
	private:
		float *data;
	public:
		const int height, width;
	private:
	
	public:
		Matrix(int _height, int _width) ;
		~Matrix();
		void setEntry(int i, int j, float value);
		float getEntry(int i, int j) const;
		Matrix* getSubmatrix(int i, int j);
		float det();
		void printMatrix();

		// Operator overloads:
		friend Matrix* operator+ (const Matrix& m1, const Matrix& m2);
		friend Matrix* operator- (const Matrix& m1, const Matrix& m2);
		friend Matrix* operator* (const Matrix& m1, const Matrix& m2);
		friend Matrix* operator* (const float& s, const Matrix& m);
		friend Matrix* operator* (const Matrix& m, const float& s);
};

Matrix* operator+ (const Matrix& m1, const Matrix& m2);
Matrix* operator- (const Matrix& m1, const Matrix& m2);
Matrix* operator* (const Matrix& m1, const Matrix& m2);
Matrix* operator* (const float& s, const Matrix& m);
Matrix* operator* (const Matrix& m, const float& s);

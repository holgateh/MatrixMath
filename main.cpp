#include <iostream>
#include "Matrix.h"
#include "MatrixHelper.h"
#include "stdlib.h"

int main()
{
	srand(time(NULL));
	Matrix* m = new Matrix(3,3);	
	m->printMatrix();	
	for(int i = 1; i <= 9; i++)
	{
		m->setEntry((i - ((i-1) % 3 + 1)) / 3 + 1, (i-1) % 3 + 1, rand() % 30); 
	}
	m->printMatrix();
	std::cout << "The determinant of m is " << m->det() << "\n";
	return 0;
}

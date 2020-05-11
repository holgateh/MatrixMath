#include "Matrix.h"
#include "MatrixHelper.h"
int main()
{
	Matrix* m = createIdentity(10); 
	Matrix* r = *m * (float)10;
	r->printMatrix();	
	return 0;
}

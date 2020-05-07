#include "Matrix.h"
#include "MatrixHelper.h"
int main()
{
	Matrix* m = createIdentity(10); 
	Matrix* q = createIdentity(10);
	Matrix* r = *m + *q;
	r->printMatrix();	
	return 0;
}

/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Author: Lucas Berg
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Matrix library:

	A simple matrix library to be used in the Multilayer Perceptron program.

OPERATIONS:
	- Add by scalar
	- Multiple by scalar
	- Matrix-Matrix addition
	- Matrix-Matrix multiplication
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#include "matrix/matrix.h"

int main (int argc, char *argv[])
{
	Matrix *m1 = new Matrix(3,2);
	m1->randomize();
	m1->print();
	
	Matrix *m2 = new Matrix(2,3);
	m2->randomize();
	m2->print();

	Matrix *m3 = Matrix::matrix_multiply(m1,m2);
	m3->print();

	Matrix *m4 = m1->transpose();
	m4->print();

	Function_t f = &f3;
	m3->map(f);
	m3->print();

	delete m4;
	delete m3;
	delete m2;
	delete m1;

	return 0;
}

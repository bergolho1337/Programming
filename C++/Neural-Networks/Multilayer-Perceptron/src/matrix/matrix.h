#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <cmath>
#include <assert.h>

#include "../utils/utils.h"

// Function pointer
typedef double (*Function_t)(double);

// Function declarations
double sigmoid (double x);
double dsigmoid (double y);

class Matrix
{
private:
    uint32_t nrows;
    uint32_t ncols;
    std::vector<double> data;
public:
    Matrix (const uint32_t nrows, const uint32_t ncols);
    void add (const double value);
    void add (Matrix *in);
    void multiply (const double value);
    void multiply (Matrix *in);
    void map (Function_t f);
    void randomize ();
    void print ();
    void print (std::string message);
    static Matrix* map (Matrix *a, Function_t f);
    static Matrix* subtract (Matrix *a, Matrix *b);
    static Matrix* matrix_multiply (Matrix *a, Matrix *b);
    static Matrix* transpose (Matrix *a);
    static Matrix* convert_from_array (std::vector<double> arr);
    static std::vector<double> convert_to_array (Matrix *a);
};

#endif
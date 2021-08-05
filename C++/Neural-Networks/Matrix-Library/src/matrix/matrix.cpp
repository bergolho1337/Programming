#include "matrix.h"

Matrix::Matrix (const uint32_t nrows, const uint32_t ncols)
{
    this->nrows = nrows;
    this->ncols = ncols;
    this->data.assign(nrows*ncols,0);
}

void Matrix::add (const double value)
{
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            this->data[i*this->ncols+j] += value;
        }
    }
}

void Matrix::add (Matrix *in)
{
    assert(this->nrows == in->nrows && this->ncols == in->ncols);
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            this->data[i*this->ncols+j] += in->data[i*this->ncols+j];
        }
    }
}

void Matrix::multiply (const double value)
{
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            this->data[i*this->ncols+j] *= value;
        }
    }
}

void Matrix::multiply (Matrix *in)
{
    assert(this->nrows == in->nrows && this->ncols == in->ncols);
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            this->data[i*this->ncols+j] *= in->data[i*this->ncols+j];
        }
    }
}

Matrix* Matrix::matrix_multiply (Matrix *a, Matrix *b)
{
    assert(a->nrows == b->ncols);
    Matrix *out = new Matrix(a->nrows,b->ncols);
    for (uint32_t i = 0; i < out->nrows; i++)
    {
        for (uint32_t j = 0; j < out->ncols; j++)
        {
            for (uint32_t k = 0; k < out->nrows; k++)
            {
                out->data[i*out->ncols+j] += a->data[i*a->ncols+k]*b->data[k*b->ncols+j]; 
            }
        }
    }
    return out;
}

Matrix* Matrix::transpose ()
{
    Matrix *out = new Matrix(this->ncols,this->nrows);
    for (uint32_t i = 0; i < out->nrows; i++)
    {
        for (uint32_t j = 0; j < out->ncols; j++)
        {
            out->data[j*this->ncols+i] = this->data[i*this->ncols+j]; 
        }
    }
    return out;
}

void Matrix::randomize ()
{
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            this->data[i*this->ncols+j] = generate_random_positive_or_negative();
        }
    }
}

void Matrix::print ()
{
    printf("----------------------------------------------------------\n");
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            printf("%5.2lf ",this->data[i*this->ncols+j]);
        }
        printf("\n");
    }
    printf("----------------------------------------------------------\n");
}

void Matrix::map (Function_t f)
{
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            this->data[i*this->ncols+j] = f(this->data[i*this->ncols+j]);
        }
    }
}

// Functions implementations
double f1 (double x)
{
    return x;
}

double f2 (double x)
{
    return x*x;
}

double f3 (double x)
{
    return x*x*x;
}
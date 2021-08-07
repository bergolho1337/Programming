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
    assert(b->nrows == a->ncols);
    Matrix *out = new Matrix(a->nrows,b->ncols);
    for (uint32_t i = 0; i < a->nrows; i++)
    {
        for (uint32_t j = 0; j < b->ncols; j++)
        {
            for (uint32_t k = 0; k < a->ncols; k++)
            {
                out->data[i*b->ncols+j] += a->data[i*a->ncols+k]*b->data[k*b->ncols+j]; 
            }
        }
    }
    return out;
}

Matrix* Matrix::transpose (Matrix *a)
{
    Matrix *result = new Matrix(a->ncols,a->nrows);
    for (uint32_t i = 0; i < a->nrows; i++)
    {
        for (uint32_t j = 0; j < a->ncols; j++)
        {
            result->data[j*a->ncols+i] = a->data[i*a->ncols+j]; 
        }
    }
    return result;
}

Matrix* Matrix::subtract (Matrix *a, Matrix *b)
{
    assert(a->nrows == b->nrows && a->ncols == b->ncols);
    Matrix *result = new Matrix(a->ncols,a->nrows);
    for (uint32_t i = 0; i < a->nrows; i++)
    {
        for (uint32_t j = 0; j < a->ncols; j++)
        {
            result->data[i*a->ncols+j] = a->data[i*a->ncols+j]-b->data[i*a->ncols+j]; 
        }
    }
    return result;
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

Matrix* Matrix::convert_from_array (std::vector<double> arr)
{
    uint32_t n = arr.size();
    Matrix *result = new Matrix(1,n);
    for (uint32_t i = 0; i < n; i++)
        result->data[i] = arr[i];
    return result;
}

std::vector<double> Matrix::convert_to_array (Matrix *a)
{
    std::vector<double> result;
    for (uint32_t i = 0; i < a->nrows; i++)
        for (uint32_t j = 0; j < a->ncols; j++)
            result.push_back(a->data[i*a->ncols+j]);
    return result;
}

void Matrix::print ()
{
    printf("----------------------------------------------------------\n");
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            printf("%5lf ",this->data[i*this->ncols+j]);
        }
        printf("\n");
    }
    printf("----------------------------------------------------------\n");
}

void Matrix::print (std::string message)
{
    printf("----------------------- %s -------------------------------\n",message.c_str());
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
        {
            printf("%5lf ",this->data[i*this->ncols+j]);
        }
        printf("\n");
    }
    printf("----------------------- %s -------------------------------\n",message.c_str());
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

Matrix* Matrix::map (Matrix *a, Function_t f)
{
    Matrix *result = new Matrix(a->nrows,a->ncols);
    for (uint32_t i = 0; i < a->nrows; i++)
    {
        for (uint32_t j = 0; j < a->ncols; j++)
        {
            result->data[i*a->ncols+j] = f(a->data[i*a->ncols+j]);
        }
    }
    return result;
}

// Functions implementations
double sigmoid (double x)
{
    return 1 / (1 + exp(-x));
}

double dsigmoid (double y)
{
    return y * (1 - y);
}
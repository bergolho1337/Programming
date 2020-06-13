#include <stdio.h>

#define STB_DS_IMPLEMENTATION
#include "stb/stb_ds.h"

// [Simple] How to create an array using the 'arrput' function, print its content and free from memory
void test_1 ()
{
    printf("[!] Executing test 1 ...\n\n");

    int *array = NULL;
    int size = 5;

    // Insert elements into the array
    for (int i = 0; i < size; i++)
    {
        int value = i;
        arrput(array,value);
    }

    // Print the array content
    printf("Array size = %d\n",arrlen(array));
    for (int i = 0; i < 5; i++)
        printf("Element %d = %d\n",i,array[i]);

    // Free from memory
    arrfree(array);

    printf("\n");
}

// [Matrix] How to create a matrix NxM using the library
void test_2 ()
{
    printf("[!] Executing test 2 ...\n\n");

    int **matrix = NULL;
    int N = 5;
    int M = 5;

    // Allocate the matrix in memory
    matrix = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; i++)
        arrsetcap(matrix[i],M);
    
    // Fill some elements
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int value = i*M + j;
            arrput(matrix[i],value);
        }
    }
            
        
    // Print the matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%5d ",matrix[i][j]);
        printf("\n");
    }
        
    // Free memory
    for (int i = 0; i < N; i++)
        arrfree(matrix[i]);
    free(matrix);

    printf("\n");
}

int main ()
{
    test_1();
    test_2();

    return 0;
}
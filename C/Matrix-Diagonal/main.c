#include <stdio.h>

int main ()
{
    double A[6][6];
    double k = 0.0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            A[i][j] = k;
            k++; 
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%5g ",A[i][j]);
        }
        printf("\n");
    }

    double sum_main_diagonal = 0.0;
    double sum_secondary_diagonal = 0.0;
    for (int i = 0; i < 6; i++)
    {
        sum_main_diagonal += A[i][i];
        sum_secondary_diagonal += A[i][5-i];
    }
    
    printf("Main diagonal = %g\n",sum_main_diagonal);
    printf("Secondary diagonal = %g\n",sum_secondary_diagonal);
        
    return 0;   
}
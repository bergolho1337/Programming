#include <iostream>
#include <cstdio>

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        printf("--------------------------------\n");
        printf("Usage:> %s <N>\n",argv[0]);
        printf("--------------------------------\n");
        printf("<N> = Number of iterations\n");
        printf("--------------------------------\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    
    for (int i = 0; i < n; i++)
    {
        printf("Iteration %d\n",i);
    }

    return 0;
}
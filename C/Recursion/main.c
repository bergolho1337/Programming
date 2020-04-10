#include <stdio.h>

void print_recursive (double a, double b)
{
    printf("%g\n",a);

    if (a < b)
        print_recursive(a+1,b);
}

int main ()
{
    double a = 5.0;
    double b = 17.0;

    print_recursive(a,b);
    return 0;
}
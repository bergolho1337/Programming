#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
    FILE *out = fopen("numbers.dat","w+");
    for (int i = 0; i < 100000; i++)
    {
        fprintf(out,"%05d\n",i);
    }
    fclose(out);
}
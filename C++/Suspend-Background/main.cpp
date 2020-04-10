#include <iostream>

using namespace std;

int main ()
{
	for (unsigned int i = 0; i < 10000000; i++)
		printf("Current at %u\n",i);
	return 0;
}

#include <iostream>
#include "package/package.h"

int main (int argc, char *argv[])
{
	Package *package = new Package();
	package->fill();
	package->print();

	for (uint32_t k = 0; k < 30; k++)
	{
		printf("Try %u\n",k+1);
		package->process();
		package->fill();
		package->print();
	}

	delete package;

	return 0;
}

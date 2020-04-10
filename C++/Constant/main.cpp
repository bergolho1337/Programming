#include <iostream>

#define E 10.0

//const double E = 10.0;

void funcao (double x)
{
	std::cout << "Hello world -- E = " << E << std::endl;
}

int main ()
{
	//static const double E = 10.0;

	funcao(1);
	return 0;
}

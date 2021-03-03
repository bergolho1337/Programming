// ------------------------------------------------------------------------------------------------------
// Template design pattern:
// The Template Method defines the steps of an algorithm and allows
// subclasses to provide the implementation for one or more steps.
// One main advantage of this design is that the algorithm is protect and stored in only one 
// place, so changes can be done efficiently.
// Another positive aspect is code reuse among the repetitive procedures.
// ******************************************************************************************************
// The Template Method version provides a framework that other caffeine beverages can be plugged into. 
// New caffeine beverages only need to implement a couple of methods. 	
// The CaffeineBeverage class concentrates knowledge about the algorithm and relies on subclasses to
// provide complete implementations.
// ------------------------------------------------------------------------------------------------------

#include "beverages/coffe/coffe.h"
#include "beverages/tea/tea.h"

int main (int argc, char *argv[])
{
	Coffe *coffe = new Coffe();
	coffe->prepareRecipe();
	std::cout << std::endl;

	Tea *tea = new Tea();
	tea->prepareRecipe();
	std::cout << std::endl;

	CoffeWithHook *coffe_hook = new CoffeWithHook();
	coffe_hook->prepareRecipe();
	std::cout << std::endl;

	return 0;
}

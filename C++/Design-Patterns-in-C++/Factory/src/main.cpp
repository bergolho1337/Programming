// ---------------------------------------------------------------------------------------------
// Factory design pattern:
// Example program that demonstrates how to implement the Factory pattern in a PizzaStore app.
// In this program there are both the Factory and the Abstract Factory pattern implemented.
// *********************************************************************************************
// FACTORY PATTERN:
// The store library is an example of the Factory pattern, which first defines an abstract class
// PizzaFactory with an abstract method createPizza() that must be implemented by the different
// pizza factories that are placed over the country. The Factory pattern is powerful, because it
// decouples the relation between the classes PizzaStore and Pizza. The PizzaStore class is only
// interest in making Pizza, the way it is going to be made is delegated to the Pizza class instead.
// *********************************************************************************************
// ABSTRACT FACTORY PATTERN:
// On the other hand, to properly made a Pizza we need a selection of specific ingredients,
// which are all defined in the ingredients library. The relation between the Pizza and the
// ingredients classes are an example of the Abstract Factory pattern. This is because when
// Pizza call the prepare() method it doesn't matter what type of Dough is going to be used,
// this decision is delegated to the PizzaIngredientFactory defined for the current
// PizzaStore we are using. That class knows which ingredient should be used in order to build
// the desired Pizza. 
// *: The Factory pattern is a really important design pattern because it relies on important
// OO principles: 
//	1) Encapsulation
//	2) Favor composition over inheritance
//	3) Program to interfaces, not implementations
//	4) Strive for loosely coupled designs between objects that interacts
//	5) Classes should be open for extension, but closed for modifications
//	6) Depend on abstractions, not on concrete classes  
// ---------------------------------------------------------------------------------------------

#include "pizza/store.h"

int main (int argc, char *argv[])
{
	// Ethan's request: New York style cheese pizza
	NYStylePizzaStore *nyPizzaStore = new NYStylePizzaStore();
	Pizza *ethanPizza = nyPizzaStore->orderPizza("cheese");
	std::cout << "Ethan ordered a " << ethanPizza->getName() << std::endl;

	std::cout << std::endl;

	// Joel's request: Chicago style cheese pizza
	ChicagoStylePizzaStore *chicagoPizzaStore = new ChicagoStylePizzaStore();
	Pizza *joelPizza = chicagoPizzaStore->orderPizza("cheese");
	std::cout << "Joel ordered a " << joelPizza->getName() << std::endl;

	delete ethanPizza;
	delete joelPizza;

	return 0;
}

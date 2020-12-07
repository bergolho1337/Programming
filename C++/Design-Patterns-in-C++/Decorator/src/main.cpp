// ---------------------------------------------------------------------------------------------
// Decorator design pattern:
// Example program that demonstrates how to implement the Observer pattern in for a Coffee store.
// ---------------------------------------------------------------------------------------------

#include <iostream>

#include "utils/stop_watch.h"
#include "utils/utils.h"
#include "starbuzz/beverage.h"
#include "starbuzz/condiment.h"

int main (int argc, char *argv[])
{
	Beverage *beverage = new Espresso();
	printf("%s -> $ %g\n",beverage->getDescription().c_str(),beverage->cost());

	Beverage *beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	printf("%s -> $ %g\n",beverage2->getDescription().c_str(),beverage2->cost());

	Beverage *beverage3 = new HouseBlend();
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);
	printf("%s -> $ %g\n",beverage3->getDescription().c_str(),beverage3->cost());

	return 0;
}

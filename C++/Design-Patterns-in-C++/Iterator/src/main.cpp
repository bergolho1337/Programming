// ------------------------------------------------------------------------------------------------------
// Iterator design pattern:
// Provides a way to access the elements of an aggregate object sequentially without exposing its underlying
// representation.
// In addition, the Iterator design pattern uses a important OO principle, which is cohesion.
// The main idea of this concept, is every responsibility of a class is an area of potential change. 
// More than one responsibility means more than one area of change. This principle guides us to
// keep each class to a single responsibility.
// ------------------------------------------------------------------------------------------------------

#include "menu/pancake.h"
#include "menu/diner.h"
#include "menu/waitress.h"

int main (int argc, char *argv[])
{
	PancakeHouseMenu *pancakeMenu = new PancakeHouseMenu();
	DinerMenu *dinerMenu = new DinerMenu();

	Waitress *waitress = new Waitress(pancakeMenu,dinerMenu);

	waitress->printMenu();

	return 0;
}

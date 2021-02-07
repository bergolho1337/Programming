// ---------------------------------------------------------------------------------------------
// Adapter design pattern:
// This program implements the Object Adapter by invoking Turkey functions inside a Duck object.
// ---------------------------------------------------------------------------------------------

#include <iostream>
#include "ducks/duck.h"

int main (int argc, char *argv[])
{
	MallardDuck *duck = new MallardDuck();
	duck->fly();
	duck->quack();

	WildTurkey *turkey = new WildTurkey();
	turkey->fly();
	turkey->gobble();

	Duck *adapter_turkey = new AdapterTurkey(turkey);
	adapter_turkey->fly();
	adapter_turkey->quack();

	return 0;
}

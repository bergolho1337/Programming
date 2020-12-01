// ---------------------------------------------------------------------------------------------
// Strategy design pattern:
// Example program that demonstrates how to use inheritance alongside interfaces in C++
// ---------------------------------------------------------------------------------------------

#include <iostream>
#include "ducks/duck.h"

int main (int argc, char *argv[])
{
	printf("Mallard duck\n");
	Duck *mallard_duck = new MallardDuck();
	mallard_duck->performFly();
	mallard_duck->performQuack();
	printf("\n");

	printf("Redhead duck\n");
	Duck *redhead_duck = new RedheadDuck();
	redhead_duck->performFly();
	redhead_duck->performQuack();
	printf("\n");

	printf("Rubber duck\n");
	Duck *rubber_duck = new RubberDuck();
	rubber_duck->performFly();
	rubber_duck->performQuack();
	printf("\n");

	printf("Decoy duck\n");
	Duck *decoy_duck = new DecoyDuck();
	decoy_duck->performFly();
	decoy_duck->performQuack();
	printf("\n");

	printf("Model duck\n");
	Duck *model_duck = new ModelDuck();
	model_duck->performFly();
	model_duck->performQuack();
	printf("\n");

	printf("Plugging a rocket in Model duck!\n");
	model_duck->setFlyBehaviour(new FlyRocketPowered);
	model_duck->performFly();
	printf("\n");

	return 0;
}

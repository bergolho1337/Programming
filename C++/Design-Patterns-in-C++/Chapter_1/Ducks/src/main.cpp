// Template C++ program

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


/*
	int n = atoi(argv[1]);

	struct stop_watch solver_time;
	init_stop_watch(&solver_time);

	start_stop_watch(&solver_time);

	solve_problem(n);
	
	long res_time = stop_stop_watch(&solver_time);
	double conv_rate = 1000.0*1000.0*60.0;
	std::cout << "Resolution Time: " << res_time << " μs (" << res_time/conv_rate << " min)" << std::endl;
*/
// Program taht demonstrates how to use the StopWatch library.
// Here, we measure the time spent to add two vectors of size n

#include <iostream>

#include "utils/stop_watch.h"

double generate_random_number ()
{
	return (double)rand()/(double)RAND_MAX;
}

void solve_problem (const int n)
{
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = generate_random_number();
		b[i] = generate_random_number();
	}

	for (int i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}

	delete [] a;
	delete [] b;
	delete [] c;	
}

int main (int argc, char *argv[])
{
	if (argc-1 != 1)
	{
		std::cout << "Usage:> " << argv[0] << " <N>" << std::endl;
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);

	struct stop_watch solver_time;
	init_stop_watch(&solver_time);

	start_stop_watch(&solver_time);

	solve_problem(n);
	
	long res_time = stop_stop_watch(&solver_time);
	double conv_rate = 1000.0*1000.0*60.0;
	std::cout << "Resolution Time: " << res_time << " μs (" << res_time/conv_rate << " min)" << std::endl;

	return 0;
}

// Template C++ program

#include <iostream>

#include "utils/stop_watch.h"
#include "utils/utils.h"

void solve_problem (const int n)
{
	// Implement me ...		
}

int main (int argc, char *argv[])
{
	if (argc-1 != 1)
	{
		usage(argv[0]);
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

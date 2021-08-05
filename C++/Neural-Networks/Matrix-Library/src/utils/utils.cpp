#include "utils.h"

double generate_random_positive_or_negative ()
{
    return (rand() % 2 == 0) ? 1.0 : -1.0;
}

double generate_random_number ()
{
    return (double)rand() / (double)RAND_MAX;
}
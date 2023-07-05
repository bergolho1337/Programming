#include "utils.h"

double generate_random_positive_or_negative ()
{
    return (rand() % 2 == 0) ? 1.0 : -1.0;
}

double generate_random_number ()
{
    return (double)rand() / (double)RAND_MAX;
}

double generate_random_number_between_interval (const double min_value, const double max_value)
{
    return generate_random_number()*(max_value-min_value) + min_value;
}

double map_function (const double x, const double min_x1, const double max_x1, const double min_x2, const double max_x2)
{
    return ( max_x2 - min_x2 ) * ( (x - min_x1)/(max_x1-min_x1) ) + min_x2;
}
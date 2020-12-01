#include "utils.h"

void usage (const char pname[])
{
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Usage:> %s\n",pname);
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Example:> %s\n",pname);
    printf("-----------------------------------------------------------------------------------------\n");
    exit(EXIT_FAILURE);
}

double calculate_mean (std::vector<double> arr)
{
    double result = 0.0;
    for (uint32_t i = 0; i < arr.size(); i++) result += arr[i];
    return result/(double)arr.size();
}

double calculate_heat_index (const double t, const double rh)
{
    return (double)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) +\
		(0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) +\
		(0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +\
		(0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) +\
        (0.0000291583 *  (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +\
		(0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +\
		0.000000000843296 * (t * t * rh * rh * rh)) -\
        (0.0000000000481975 * (t * t * t * rh * rh * rh)));
}
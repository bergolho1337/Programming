#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <cstdio>

void usage (const char pname[]);
double calculate_mean (std::vector<double> arr);
double calculate_heat_index (const double t, const double rh);

#endif /* __STOPWATCH_H */

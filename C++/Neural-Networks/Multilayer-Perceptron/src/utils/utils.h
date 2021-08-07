#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <cassert>

#define PRINT_LINE "==============================================================================================================="

// ----------------------------------------------------
// Domain limits
const double WIDTH = 400.0;     // Output domain
const double HEIGHT = 400.0;    // Output domain
const double MIN_X = -1;        // Reference domain
const double MAX_X = 1;         // Reference domain
const double MIN_Y = -1;        // Reference domain
const double MAX_Y = 1;         // Reference domain
// ----------------------------------------------------

double generate_random_number ();
double generate_random_number_between_interval (const double min_value, const double max_value);
double generate_random_positive_or_negative ();
double map_function (const double x, const double min_x1, const double max_x1, const double min_x2, const double max_x2);
std::vector<double> compute_error (std::vector<double> a, std::vector<double> b);

#endif
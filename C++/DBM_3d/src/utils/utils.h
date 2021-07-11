//
// Created by bergolho on 19/02/19.
//

#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <cmath>
#include <sys/stat.h> 
#include <sys/types.h> 

#include <string>
#include <sstream>
#include <vector>


// ==========================================================================================================================
// CONSTANTS AND MACROS
#define UM_TO_CM 0.0001
#define UM_TO_M 1.0E-06
#define CM_TO_UM 1.0E+05
#define MM_TO_UM 1.0E+03
#define M_TO_UM 1.0E+06
#define M_TO_MM 1.0E+03
#define MS_TO_S 0.001
#define S_TO_MS 1000.0
#define CM_S_TO_M_S 0.01
#define MS_TO_US 1000.0
#define CM_TO_MM 10.0
#define CM_TO_M 0.01

static const double EPSILON = 1.0e-16;                   // Tolerance for comparing real numbers
static const uint32_t MAX_FILENAME_SIZE = 500;           // Maximum filename size
// ==========================================================================================================================

void usage (const char pname[]);
void create_directory (const char *path);
void calc_mean_std (std::vector<double> arr, double &mean, double &std);
void write_vector_to_file (std::vector<double> arr, std::string filename);

double euclidean_norm (const double x1, const double y1, const double z1,\
                    const double x2, const double y2, const double z2);
double calc_angle_between_vectors (const double u[], const double v[]);

bool check_user_input (int argc, char *argv[]);
bool check_extension (std::string filename, std::string target_extension);
bool check_folder (std::string filename);

#endif

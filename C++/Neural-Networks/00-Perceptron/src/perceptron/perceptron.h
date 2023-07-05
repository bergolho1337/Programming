#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>

#include "../utils/utils.h"
#include "training.h"

class Perceptron
{
private:
    std::vector<double> inputs;
    std::vector<double> weights;

    void initialize (const uint32_t n, const double arr[]);
    double guess ();
    double activation_function (double value);
    void update_weigths (const double error);
    void draw_guess_set (std::vector<Point> t_set, const char filename[]);
public:
    Perceptron (uint32_t n = 2);
    Perceptron (const uint32_t n, const double arr[]);

    void train (Training_Set *training_set);
    void evaluate (Training_Set *evaluate_set);
    void print ();
};

#endif
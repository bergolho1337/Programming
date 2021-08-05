#ifndef MULTILAYER_H
#define MULTILAYER_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>

#include "../matrix/matrix.h"
#include "../utils/utils.h"

class MultilayerPerceptron
{
private:
    uint32_t num_inputs;            // Number of input layers
    uint32_t num_hidden;            // Number of hidden layers
    uint32_t num_outputs;           // Number of output layers

    Matrix *weights_ih;             // Weights matrix from input to hidden layer
    Matrix *weights_ho;             // Weights matrix from hidden to output layer

    Matrix *bias_h;                 // Bias of the hidden layer
    Matrix *bias_o;                 // Bias of the output layer

/*
    void initialize (const uint32_t n, const double arr[]);
    double guess ();
    double activation_function (double value);
    void update_weigths (const double error);
    void draw (std::vector<Point> t_set, const uint32_t iter);
    void draw_points (std::vector<Point> t_set, const uint32_t iter);
    void draw_line (const uint32_t iter);
*/
public:
    static constexpr double BIAS = 1.0;

    MultilayerPerceptron (const uint32_t num_inputs, const uint32_t num_hidden, const uint32_t num_outputs);
    ~MultilayerPerceptron ();
    void train (std::vector< std::vector<double> > inputs, std::vector<double> answer);
    std::vector<double> evaluate (std::vector<double> inputs);
    void print ();
};

#endif
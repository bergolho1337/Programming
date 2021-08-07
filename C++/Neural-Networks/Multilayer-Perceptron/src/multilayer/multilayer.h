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

    double learning_rate;           // Learning rate of the neural network

    Matrix *weights_ih;             // Weights matrix from input to hidden layer
    Matrix *weights_ho;             // Weights matrix from hidden to output layer

    Matrix *bias_h;                 // Bias of the hidden layer
    Matrix *bias_o;                 // Bias of the output layer

    Function_t activation_function; // Reference to the activation function

    

public:
    MultilayerPerceptron (const uint32_t num_inputs, const uint32_t num_hidden, const uint32_t num_outputs);
    ~MultilayerPerceptron ();
    void setLearningRate (double learning_rate = 0.1);
    void setActivationFunction (Function_t f = sigmoid);
    void train (std::string filename);
    void read_training_set (std::string filename,\
                            std::vector< std::vector<double> > &inputs,\
                            std::vector< std::vector<double> > &answers);
    std::vector<double> evaluate (std::vector<double> input);
    void print ();
};

#endif
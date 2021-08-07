/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Author: Lucas Berg
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Neural network:

	In this project a neural network (MultilayerPerceptron) is constructed to solve the XOR problem. This type of neural network is commonly
	applied in problems that are not linearly separable, which cannot be solved using a simple Perceptron network. The training aspect of this
	implementation is based on supervised learning, where we have the expected output for a given input. The weigths of the layers are adjusted
	using backpropagation and gradient descent.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Problem:

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#include "multilayer/multilayer.h"

int main (int argc, char *argv[])
{
	MultilayerPerceptron *mperceptron = new MultilayerPerceptron(2,4,1);
	//mperceptron->print();

	// TRAINING
	mperceptron->train("inputs/training_set.txt");
	
	// EVALUATION
/*
	std::vector<double> inputs_1 = {0,0};
	std::vector<double> inputs_2 = {1,0};
	std::vector<double> inputs_3 = {0,1};
	std::vector<double> inputs_4 = {1,1};
	std::vector<double> output_1 = mperceptron->evaluate(inputs_1);
	std::vector<double> output_2 = mperceptron->evaluate(inputs_2);
	std::vector<double> output_3 = mperceptron->evaluate(inputs_3);
	std::vector<double> output_4 = mperceptron->evaluate(inputs_4);
	printf("%g ^ %g = %g [0]\n",inputs_1[0],inputs_1[1],output_1[0]);
	printf("%g ^ %g = %g [1]\n",inputs_2[0],inputs_2[1],output_2[0]);
	printf("%g ^ %g = %g [1]\n",inputs_3[0],inputs_3[1],output_3[0]);
	printf("%g ^ %g = %g [0]\n",inputs_4[0],inputs_4[1],output_4[0]);
*/
	delete mperceptron;

	return 0;
}

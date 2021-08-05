/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Author: Lucas Berg
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Neural network:

	In this project a neural network (MultilayerPerceptron) is constructed to solve the XOR problem. This type of neural network is commonly
	applied in problems that are not linearly separable, which cannot be solved using a simple Perceptron network.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Problem:
	Given a 

Domain configuration:			 ^   y
						 _______ ._________(1,1)			 __________________(WIDTH,HEIGHT)
						|		 .		   |				|				   |
						|		 .		   |				|				   |
						|................... > x =====> 	|				   |
						|   (0,0).		   |				|				   |
						|		 .		   |				|				   |
				(-1-1)  |________._________|		   (0,0)|__________________|
				
						 "reference domain"					   "output domain"

Perceptron sketch:

Input							Neuron						Output						| Inside the neuron: (Feed forward)
                   w0																	| _2_
x0 (x)		----------------->											+1 (region A)	| \				 PASS THE RESULT TO THE
				   w1			  N	     ----------------->    y						| /__ xi wi => 	  ACTIVATION FUNCTION
x1 (y)		----------------->	  ^										-1 (region B)	| i=0
								  |														|
	      x2 = 1 (BIAS) __________|	w2				

The main idea of the program is that we will first give to the Perceptron a point, which we already know its region, and ask for the neural
network to make a guess of what region that point should be. If the guess is incorrect then we will adjust the Perceptron parameters by using
a Gradient Descent procedure in order to improve its accuracy.

REMINDER:
This program uses the VTK library to visually demonstrate how the training process was done and also a way to see the training and evaluate sets. 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#include "multilayer/multilayer.h"

int main (int argc, char *argv[])
{
	MultilayerPerceptron *mperceptron = new MultilayerPerceptron(2,2,1);
	mperceptron->print();

	std::vector<double> inputs = {0,1};
	std::vector<double> output = mperceptron->evaluate(inputs);

	delete mperceptron;

	return 0;
}

/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Author: Lucas Berg
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Neural network:

	In this project the simplest possible neural network (Perceptron) is constructed to solve a simple classification problem using a
Supervised Learning technique.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Problem:
	Given a 2D space and a line that separates this space into two regions A and B. Write a program that is able to correctly classify if
a given point with coordinates (x,y) is inside region A or B. 

Domain configuration:
 ______
|	  /|
| +1 / |
|	/  |		y = x
|  /   |
| /	-1 |
|/_____|	

Perceptron sketch:

Input							Neuron						Output						| Inside the neuron: (Feed forward)
                   w0																	| _1_
x0 (x)		----------------->											+1 (region A)	| \				 PASS THE RESULT TO THE
				   w1			  N	     ----------------->    y						| /__ xi wi => 	  ACTIVATION FUNCTION
x1 (y)		----------------->											-1 (region B)	| i=0
																						|
								

The main idea of the program is that we will first give to the Perceptron a point, which we already know its region, and ask for the neural
network to make a guess of what region that point should be. If the guess is incorrect then we will adjust the Perceptron parameters by using
a Gradient Descent procedure in order to improve its accuracy.

REMINDER:
This program uses the VTK library to visually demonstrate how the training process was done and also a way to see the training and evaluate sets. 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#include "perceptron/perceptron.h"
#include "perceptron/training.h"

int main (int argc, char *argv[])
{
	Perceptron *the_perceptron = new Perceptron();
	//the_perceptron->print();

	Training_Set *training_set = new Training_Set();
	training_set->draw();
	the_perceptron->train(training_set);

	Training_Set *evaluate_set = new Training_Set(500);
	the_perceptron->evaluate(evaluate_set);

	delete the_perceptron;
	delete training_set;
	delete evaluate_set;
	
	return 0;
}

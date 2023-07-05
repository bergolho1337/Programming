/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Author: Lucas Berg
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Neural network:

	In this project the simplest possible neural network (Perceptron) is constructed to solve a simple classification problem using a
Supervised Learning technique. In this program we introduce the usage of a bias to manage the case where the point (0,0) is given as an
input. Additionally, the code was optimized and generalized to work with any given function that divides the 2D domain.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Problem:
	Given a 2D space and a line that separates this space into two regions A and B. Write a program that is able to correctly classify if
a given point with coordinates (x,y) is inside region A or B. Your program must also translate the given domain to the [-1,1]x[-1,1] system.

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

#include "perceptron/perceptron.h"
#include "perceptron/training.h"

int main (int argc, char *argv[])
{
	Perceptron *the_perceptron = new Perceptron();
	//the_perceptron->print();

	Training_Set *training_set = new Training_Set();
	//training_set->print();
	training_set->draw();
	the_perceptron->train(training_set);

	Training_Set *evaluate_set = new Training_Set(500);
	the_perceptron->evaluate(evaluate_set);

	delete the_perceptron;
	delete training_set;
	delete evaluate_set;
	
	return 0;
}

// -------------------------------------------------------------------------------------------------------
// Singleton design pattern:
// Example program that demonstrates how to implement the Singleton pattern in a ChocolateBoiler app.
// ********************************************************************************************************
// SINGLETON PATTERN:
// The Singleton design pattern ensures a class only has one instance and provide a global
// point of acess. Normally, this design is used when classes are been within a multithreading
// environment, in order to avoid race conditions between objects. 
// The main idea of the Singleton pattern is to make the constructor of the Singleton class private and 
// acessible with a static class method, which is normally called getInstance(). 
// This way each time the user wants a Singleton object it will receive its unique reference.
// --------------------------------------------------------------------------------------------------------

#include "chocolate/boiler.h"

// Thread 1 will have one instance of the ChocolateBoiler
void Thread_One ()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	ChocolateBoiler *chocolateBoiler = ChocolateBoiler::getInstance();
	// Empty boiler around here ...
	chocolateBoiler->print();
}

// Thread 2 will have another instance of the ChocolateBoiler
void Thread_Two ()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	ChocolateBoiler *chocolateBoiler = ChocolateBoiler::getInstance();
	
	// Full and boiled chocolate here ...
	chocolateBoiler->fill();
	chocolateBoiler->boil();

	chocolateBoiler->print();
}

int main (int argc, char *argv[])
{
	// Create two threads and execute then in parallel
	std::thread t1(Thread_One);
	std::thread t2(Thread_Two);

	// Join the threads and terminate the program
	t1.join();
	t2.join();
	
	return 0;
}

#ifndef COFFE_H
#define COFFE_H

#include "../beverage.h"

class Coffe : public CaffeineBeverage
{
private:

public:
    Coffe ();
    void brew ();               // Abstract methods that need to be implemented by the subclasses 
    void addCondiments ();      // Abstract methods that need to be implemented by the subclasses
};

class CoffeWithHook : public CaffeineBeverageWithHook
{
private:

public:
    CoffeWithHook ();
    void brew ();               // Abstract methods that need to be implemented by the subclasses 
    void addCondiments ();      // Abstract methods that need to be implemented by the subclasses
    std::string getUserInput ();
};

#endif
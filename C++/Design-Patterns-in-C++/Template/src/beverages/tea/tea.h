#ifndef TEA_H
#define TEA_H

#include "../beverage.h"

class Tea : public CaffeineBeverage
{
private:

public:
    Tea ();
    void brew ();               // Abstract methods that need to be implemented by the subclasses 
    void addCondiments ();      // Abstract methods that need to be implemented by the subclasses
};

#endif
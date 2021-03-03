#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>

class CaffeineBeverage
{
private:

public:
    void boilWater ();                      // Inherited normally by the subclasses
    void pourInCup ();                      // Inherited normally by the subclasses
    virtual void brew () = 0;               // Abstract methods that need to be implemented by the subclasses 
    virtual void addCondiments () = 0;      // Abstract methods that need to be implemented by the subclasses
    virtual void prepareRecipe () final;    // Method that cannot be overwritten by the subclasses (Template method)
};

class CaffeineBeverageWithHook
{
private:

public:
    void boilWater ();                      // Inherited normally by the subclasses
    void pourInCup ();                      // Inherited normally by the subclasses
    bool customerWantsCondiments ();        // Hook function
    virtual void brew () = 0;               // Abstract methods that need to be implemented by the subclasses 
    virtual void addCondiments () = 0;      // Abstract methods that need to be implemented by the subclasses
    virtual void prepareRecipe () final;    // Method that cannot be overwritten by the subclasses (Template method)
private:
    virtual std::string getUserInput () = 0;
};

#endif
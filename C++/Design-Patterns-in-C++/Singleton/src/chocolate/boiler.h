#ifndef BOILER_H
#define BOILER_H

#include <iostream>
#include <thread>
#include <chrono>

class ChocolateBoiler
{
private:
    bool empty;
    bool boiled;
    static ChocolateBoiler *uniqueInstance;
    ChocolateBoiler ();
public:
    static ChocolateBoiler* getInstance ()
    {
        if (uniqueInstance == NULL)
            uniqueInstance = new ChocolateBoiler();
        return uniqueInstance;
    }
    void fill ();
    void drain ();
    void boil ();
    void print ();
    bool isEmpty ();
    bool isBoiled ();
};

#endif 

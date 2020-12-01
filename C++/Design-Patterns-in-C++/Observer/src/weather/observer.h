#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include <cstdio>

// Abstract class - Interface
class Observer
{
public:
    virtual void update (const double temp, const double hum, const double press) = 0;
    virtual void display () = 0;
};

// Abstract class - Interface
class Subject
{
public:
    virtual void registerObserver (Observer *o) = 0;
    virtual void removeObserver (const uint32_t id) = 0;
    virtual void notifyObservers () = 0;
};


#endif

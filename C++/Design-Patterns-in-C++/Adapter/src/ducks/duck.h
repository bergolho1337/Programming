#ifndef DUCK_H
#define DUCK_H

#include <iostream>
#include <cstdio>

#include "turkey.h"

// Super class
class Duck 
{
public:
    Duck ();
    virtual void fly () = 0;
    virtual void quack () = 0;
    virtual void display () = 0;
};

// Types of ducks
class MallardDuck : public Duck
{
public:
    MallardDuck ();
    void fly ();
    void quack ();
    void display ();
};

class AdapterTurkey : public Duck
{
private:
    Turkey *turkey;
public:
    AdapterTurkey (Turkey *turkey);
    void fly ();
    void quack ();
    void display ();    
};

#endif

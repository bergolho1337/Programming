#ifndef DUCK_H
#define DUCK_H

#include <iostream>
#include <cstdio>

#include "behaviour.h"

// Super class
class Duck 
{
protected:
    FlyBehaviour *fly_behaviour;
    QuackBehaviour *quack_behaviour;
public:
    Duck ();
    void swim ();
    void performFly ();
    void performQuack ();
    void setFlyBehaviour (FlyBehaviour *fb);
    void setQuackBehaviour (QuackBehaviour *qb);
    virtual void display () = 0;
};

// Types of ducks
class MallardDuck : public Duck
{
public:
    MallardDuck ();
    void display ();
};

class RedheadDuck : public Duck
{
public:
    RedheadDuck ();
    void display ();
};

class RubberDuck : public Duck
{
public:
    RubberDuck ();
    void display ();
};

class DecoyDuck : public Duck
{
public:
    DecoyDuck ();
    void display ();
};

class ModelDuck : public Duck
{
public:
    ModelDuck ();
    void display ();
};

#endif

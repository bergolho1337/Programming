#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <iostream>
#include <cstdio>

// Abstract class - Interface
class FlyBehaviour
{
public:
    virtual void fly () = 0;
};

// Types of fly
class FlyWithWings : public FlyBehaviour
{
public:
    void fly ();
};

class FlyNoWay : public FlyBehaviour
{
public:
    void fly ();
};

class FlyRocketPowered : public FlyBehaviour
{
public:
    void fly ();
};

// Abstract class - Interface
class QuackBehaviour
{
public:
    virtual void quack () = 0;
};

// Types of quack
class Quack : public QuackBehaviour
{
public:
    void quack ();
};

class Squeak : public QuackBehaviour
{
public:
    void quack ();
};

class MuteQuack : public QuackBehaviour
{
public:
    void quack ();
};

#endif

#ifndef CONDIMENT_H
#define CONDIMENT_H

#include "beverage.h"

// Abstract class - Decorator
class CondimentDecorator : public Beverage
{
public:
    virtual std::string getDescription () = 0;
};

// Types of condiments
class Mocha : public CondimentDecorator
{
private:
    Beverage *beverage;
public:
    Mocha (Beverage *beverage);
    std::string getDescription ();
    double cost ();
};

class SteamedMilk : public CondimentDecorator
{
private:
    Beverage *beverage;
public:
    SteamedMilk (Beverage *beverage);
    std::string getDescription ();
    double cost ();
};

class Soy : public CondimentDecorator
{
private:
    Beverage *beverage;
public:
    Soy (Beverage *beverage);
    std::string getDescription ();
    double cost ();
};

class Whip : public CondimentDecorator
{
private:
    Beverage *beverage;
public:
    Whip (Beverage *beverage);
    std::string getDescription ();
    double cost ();
};

#endif

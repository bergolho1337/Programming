#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>
#include <string>
#include <cstdio>

// Abstract class - Component
class Beverage
{
protected:
    std::string description;
public:
    virtual std::string getDescription () = 0;
    virtual double cost () = 0;
};

// Types of beverages
class Espresso : public Beverage
{
public:
    Espresso ();
    std::string getDescription ();
    double cost ();
};

class HouseBlend : public Beverage
{
public:
    HouseBlend ();
    std::string getDescription ();
    double cost ();
};

class DarkRoast : public Beverage
{
public:
    DarkRoast ();
    std::string getDescription ();
    double cost ();
};

class Decaf : public Beverage
{
public:
    Decaf ();
    std::string getDescription ();
    double cost ();
};

#endif

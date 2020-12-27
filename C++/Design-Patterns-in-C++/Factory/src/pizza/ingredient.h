#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdarg>

// ----------------------------------------------------------------------------------------
// Ingredients - Abstract classes
class Dough
{
protected:
    std::string name;
public:
    Dough () {};        
};

class Veggie
{
protected:
    std::string name;
public:
    Veggie () {};
};

class Sauce
{
protected:
    std::string name;
public:
    Sauce () {};
};

class Cheese
{
protected:
    std::string name;
public:
    Cheese () {}
};

class Clams
{
protected:
    std::string name;
public:
    Clams () {};
};

// ----------------------------------------------------------------------------------------
// Ingredients - Concrete classes 
class ThinCrustDough : public Dough
{
public:
    ThinCrustDough () {};
};

class ThickCrustDough : public Dough
{
public:
    ThickCrustDough () {};
};

class MarinaraSauce : public Sauce
{
public:
    MarinaraSauce () {};
};

class PlumTomatoSauce : public Sauce
{
public:
    PlumTomatoSauce () {};
};


class ReggianoCheese : public Cheese
{
public:
    ReggianoCheese () {};
};

class MozzarellaCheese : public Cheese
{
public:
    MozzarellaCheese () {};
};

class FreshClams : public Clams
{
public:
    FreshClams () {};
};

class FrozenClams : public Clams
{
public:
    FrozenClams () {};
};

class Pepperoni
{
protected:
    std::string name;
public:
    Pepperoni () {};
};

class SlicedPepperoni : public Pepperoni
{
public:
    SlicedPepperoni () {};
};

class Garlic : public Veggie
{
public:
    Garlic () {};
};

class Onion : public Veggie
{
public:
    Onion () {};
};

class Mushroom : public Veggie
{
public:
    Mushroom () {};
};

class RedPepper : public Veggie
{
public:
    RedPepper () {};
};

class Oregano : public Veggie
{
public:
    Oregano () {};
};

// ----------------------------------------------------------------------------------------
// Abstract Factory - Ingredients
class PizzaIngredientFactory
{
public:
    virtual Dough* createDough () = 0;
    virtual Sauce* createSauce () = 0;
    virtual Cheese* createCheese () = 0;
    virtual Pepperoni* createPepperoni () = 0;
    virtual Clams* createClams () = 0;
    virtual std::vector<Veggie*> createVeggies (uint32_t num_veggies, ...) = 0;
};

// Types of ingredient factory
class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    Dough* createDough ();
    Sauce* createSauce ();
    Cheese* createCheese ();
    Pepperoni* createPepperoni ();
    Clams* createClams ();
    std::vector<Veggie*> createVeggies (uint32_t num_veggies, ...);
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    Dough* createDough ();
    Sauce* createSauce ();
    Cheese* createCheese ();
    Pepperoni* createPepperoni ();
    Clams* createClams ();
    std::vector<Veggie*> createVeggies (uint32_t num_veggies, ...);
};

#endif 

#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "ingredient.h"

// Abstract class - Interface
class Pizza
{
protected:
    std::string name;
    Dough *dough;
    Sauce *sauce;
    Cheese *cheese;
    Pepperoni *pepperoni;
    Clams *clams;
    std::vector<Veggie*> veggies;
public:
    void setName (std::string name) { this->name = name; }
    std::string getName () { return this->name; }
    virtual void prepare () = 0;
    virtual void bake () = 0;
    virtual void cut () = 0;
    virtual void box () = 0;
};

// Types of pizza
class CheesePizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
public:
    CheesePizza (PizzaIngredientFactory *factory);
    void prepare ();
    void bake ();
    void cut ();
    void box ();
};

class PepperoniPizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
public:
    PepperoniPizza (PizzaIngredientFactory *factory);
    void prepare ();
    void bake ();
    void cut ();
    void box ();
};

class ClamPizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
public:
    ClamPizza (PizzaIngredientFactory *factory);
    void prepare ();
    void bake ();
    void cut ();
    void box ();
};

class VeggiePizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
public:
    VeggiePizza (PizzaIngredientFactory *factory);
    void prepare ();
    void bake ();
    void cut ();
    void box ();
};

#endif 

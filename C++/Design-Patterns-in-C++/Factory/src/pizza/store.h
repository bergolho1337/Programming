#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <cstdio>

#include "pizza.h"

class PizzaStore
{
protected:
    PizzaIngredientFactory *ingredientFactory;
public:
    Pizza* orderPizza (std::string type);
    virtual Pizza* createPizza (std::string type) = 0;
};

class NYStylePizzaStore : public PizzaStore
{
public:
    Pizza* createPizza (std::string type);
};

class ChicagoStylePizzaStore : public PizzaStore
{
public:
    Pizza* createPizza (std::string type);
};

#endif 

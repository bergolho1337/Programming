#include "ingredient.h"

Dough* NYPizzaIngredientFactory::createDough ()
{
    return new ThinCrustDough();
}

Sauce* NYPizzaIngredientFactory::createSauce ()
{
    return new MarinaraSauce();
}

Cheese* NYPizzaIngredientFactory::createCheese ()
{
    return new ReggianoCheese();
}

Clams* NYPizzaIngredientFactory::createClams ()
{
    return new FreshClams();
}

Pepperoni* NYPizzaIngredientFactory::createPepperoni ()
{
    return new SlicedPepperoni();
}

std::vector<Veggie*> NYPizzaIngredientFactory::createVeggies (uint32_t num_veggies, ...)
{
    std::vector<Veggie*> veggies;
    va_list valist;
    va_start(valist,num_veggies);
    for (uint32_t i = 0; i < num_veggies; i++)
    {
        Veggie *veggie = va_arg(valist,Veggie*);
        veggies.push_back(veggie);
    }
    va_end(valist);
    return veggies;
}

Dough* ChicagoPizzaIngredientFactory::createDough ()
{
    return new ThickCrustDough();
}

Sauce* ChicagoPizzaIngredientFactory::createSauce ()
{
    return new PlumTomatoSauce();
}

Cheese* ChicagoPizzaIngredientFactory::createCheese ()
{
    return new MozzarellaCheese();
}

Clams* ChicagoPizzaIngredientFactory::createClams ()
{
    return new FrozenClams();
}

Pepperoni* ChicagoPizzaIngredientFactory::createPepperoni ()
{
    return new SlicedPepperoni();
}

std::vector<Veggie*> ChicagoPizzaIngredientFactory::createVeggies (uint32_t num_veggies, ...)
{
    std::vector<Veggie*> veggies;
    va_list valist;
    va_start(valist,num_veggies);
    for (uint32_t i = 0; i < num_veggies; i++)
    {
        Veggie *veggie = va_arg(valist,Veggie*);
        veggies.push_back(veggie);
    }
    va_end(valist);
    return veggies;
}
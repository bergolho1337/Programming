#include "pizza.h"

void Pizza::bake ()
{
    std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::cut ()
{
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::box ()
{
    std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

CheesePizza::CheesePizza (PizzaIngredientFactory *factory)
{
    this->ingredientFactory = factory;
}

void CheesePizza::prepare ()
{
    std::cout << "Preparing " << this->name << std::endl;
    this->dough = ingredientFactory->createDough();
    this->sauce = ingredientFactory->createSauce();
    this->cheese = ingredientFactory->createCheese();
}

void CheesePizza::bake ()
{
    Pizza::bake();
}

void CheesePizza::cut ()
{
    Pizza::cut();
}

void CheesePizza::box ()
{
    Pizza::box();
}

PepperoniPizza::PepperoniPizza (PizzaIngredientFactory *factory)
{
    this->ingredientFactory = factory;
}

void PepperoniPizza::prepare ()
{
    std::cout << "Preparing " << this->name << std::endl;
    this->dough = ingredientFactory->createDough();
    this->sauce = ingredientFactory->createSauce();
    this->cheese = ingredientFactory->createCheese();
    this->pepperoni = ingredientFactory->createPepperoni();
    this->veggies = ingredientFactory->createVeggies(3, new Onion(), new Mushroom(), new RedPepper());
}

void PepperoniPizza::bake ()
{
    Pizza::bake();
}

void PepperoniPizza::cut ()
{
    Pizza::cut();
}

void PepperoniPizza::box ()
{
    Pizza::box();
}

ClamPizza::ClamPizza (PizzaIngredientFactory *factory)
{
    this->ingredientFactory = factory;
}

void ClamPizza::prepare ()
{
    std::cout << "Preparing " << this->name << std::endl;
    this->dough = ingredientFactory->createDough();
    this->sauce = ingredientFactory->createSauce();
    this->cheese = ingredientFactory->createCheese();
    this->clams = ingredientFactory->createClams();
}

void ClamPizza::bake ()
{
    Pizza::bake();
}

void ClamPizza::cut ()
{
    Pizza::cut();
}

void ClamPizza::box ()
{
    Pizza::box();
}

VeggiePizza::VeggiePizza (PizzaIngredientFactory *factory)
{
    this->ingredientFactory = factory;
}

void VeggiePizza::prepare ()
{
    std::cout << "Preparing " << this->name << std::endl;
    this->dough = ingredientFactory->createDough();
    this->sauce = ingredientFactory->createSauce();
    this->cheese = ingredientFactory->createCheese();
    this->veggies = ingredientFactory->createVeggies(3, new Onion(), new Mushroom(), new RedPepper());
}

void VeggiePizza::bake ()
{
    Pizza::bake();
}

void VeggiePizza::cut ()
{
    Pizza::cut();
}

void VeggiePizza::box ()
{
    Pizza::box();
}


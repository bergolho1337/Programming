#include "store.h"

Pizza* PizzaStore::orderPizza (std::string type)
{
    Pizza *pizza = createPizza(type);

    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return pizza;
}

Pizza* NYStylePizzaStore::createPizza (std::string type)
{
    Pizza *pizza = NULL;
    this->ingredientFactory = new NYPizzaIngredientFactory();

    if (type == "cheese")
    {
        pizza = new CheesePizza(this->ingredientFactory);
        pizza->setName("New York Style Cheese Pizza");
    }
    else if (type == "pepperoni")
    {
        pizza = new PepperoniPizza(this->ingredientFactory);
        pizza->setName("New York Style Pepperoni Pizza");
    }
    else if (type == "clam")
    {   
        pizza = new ClamPizza(this->ingredientFactory);
        pizza->setName("New York Style Clam Pizza");
    }
    else if (type == "veggie")
    {
        pizza = new VeggiePizza(this->ingredientFactory);
        pizza->setName("New York Style Veggie Pizza");
    }
    
    return pizza;
}

Pizza* ChicagoStylePizzaStore::createPizza (std::string type)
{
    Pizza *pizza = NULL;
    this->ingredientFactory = new ChicagoPizzaIngredientFactory();

    if (type == "cheese")
    {
        pizza = new CheesePizza(this->ingredientFactory);
        pizza->setName("Chicago Style Cheese Pizza");
    }
    else if (type == "pepperoni")
    {
        pizza = new PepperoniPizza(this->ingredientFactory);
        pizza->setName("Chicago Style Pepperoni Pizza");
    }
    else if (type == "clam")
    {   
        pizza = new ClamPizza(this->ingredientFactory);
        pizza->setName("Chicago Style Clam Pizza");
    }
    else if (type == "veggie")
    {
        pizza = new VeggiePizza(this->ingredientFactory);
        pizza->setName("Chicago Style Veggie Pizza");
    }
    
    return pizza;   
}
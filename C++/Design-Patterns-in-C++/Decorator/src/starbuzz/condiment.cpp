#include "condiment.h"

Mocha::Mocha (Beverage *beverage)
{
    this->beverage = beverage;
}

std::string Mocha::getDescription ()
{
    return beverage->getDescription() + ", Mocha";
}

double Mocha::cost ()
{
    return 0.20 + beverage->cost();
}

SteamedMilk::SteamedMilk (Beverage *beverage)
{
    this->beverage = beverage;
}

std::string SteamedMilk::getDescription ()
{
    return beverage->getDescription() + ", Steamed Milk";
}

double SteamedMilk::cost ()
{
    return 0.10 + beverage->cost();
}

Soy::Soy (Beverage *beverage)
{
    this->beverage = beverage;
}

std::string Soy::getDescription ()
{
    return beverage->getDescription() + ", Soy";
}

double Soy::cost ()
{
    return 0.15 + beverage->cost();
}

Whip::Whip (Beverage *beverage)
{
    this->beverage = beverage;
}

std::string Whip::getDescription ()
{
    return beverage->getDescription() + ", Whip";
}

double Whip::cost ()
{
    return 0.10 + beverage->cost();
}
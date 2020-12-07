#include "beverage.h"

Espresso::Espresso ()
{
    this->description = "Espresso";
}

std::string Espresso::getDescription ()
{
    return this->description;
}

double Espresso::cost ()
{
    return 1.99;
}

HouseBlend::HouseBlend ()
{
    this->description = "House Blend Coffee";
}

std::string HouseBlend::getDescription ()
{
    return this->description;
}

double HouseBlend::cost ()
{
    return 0.89;
}

DarkRoast::DarkRoast ()
{
    this->description = "Dark Roast Coffee";
}

std::string DarkRoast::getDescription ()
{
    return this->description;
}

double DarkRoast::cost ()
{
    return 0.99;
}

Decaf::Decaf ()
{
    this->description = "Decaf";
}

std::string Decaf::getDescription ()
{
    return this->description;
}

double Decaf::cost ()
{
    return 1.05;
}
#include "boiler.h"

// Initialize the static variable
ChocolateBoiler* ChocolateBoiler::uniqueInstance = NULL;

ChocolateBoiler::ChocolateBoiler ()
{
    this->empty = true;
    this->boiled = false;
}

void ChocolateBoiler::fill ()
{
    if (isEmpty())
    {
        this->empty = false;
        this->boiled = false;
    }
}

void ChocolateBoiler::drain ()
{
    if (!isEmpty() && isBoiled())
    {
        this->empty = true;
    }
}

void ChocolateBoiler::boil ()
{
    if (!isEmpty() && !isBoiled())
    {
        this->boiled = true;
    }
}

bool ChocolateBoiler::isEmpty ()
{
    return this->empty;
}

bool ChocolateBoiler::isBoiled ()
{
    return this->boiled;
}

void ChocolateBoiler::print ()
{
    if (isEmpty())
        std::cout << "Boiler is empty!" << std::endl;
    else
        std::cout << "Boiler is full!" << std::endl;

    if (isBoiled())
        std::cout << "Chocolate is boiled!" << std::endl;
    else
        std::cout << "Chocolate is normal!" << std::endl;
    
}
#include "beverage.h"

void CaffeineBeverage::boilWater ()
{
    printf("Boiling water ...\n");
}

void CaffeineBeverage::pourInCup ()
{
    printf("Pouring into cup ...\n");
}

void CaffeineBeverage::prepareRecipe () 
{
    boilWater();
    brew();
    pourInCup();
    addCondiments();
}

void CaffeineBeverageWithHook::boilWater ()
{
    printf("Boiling water ...\n");
}

void CaffeineBeverageWithHook::pourInCup ()
{
    printf("Pouring into cup ...\n");
}

bool CaffeineBeverageWithHook::customerWantsCondiments ()
{
    std::string answer = getUserInput();
    
    return (answer == "yes" || answer == "y") ? true : false;        
}

void CaffeineBeverageWithHook::prepareRecipe () 
{
    boilWater();
    brew();
    pourInCup();
    if (customerWantsCondiments())  addCondiments();
}
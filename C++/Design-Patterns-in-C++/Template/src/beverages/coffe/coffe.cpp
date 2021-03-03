#include "coffe.h"

Coffe::Coffe ()
{

}

void Coffe::brew ()
{
    printf("Dripping Coffee through filter\n");
}

void Coffe::addCondiments ()
{
    printf("Adding milk and sugar\n");
}

CoffeWithHook::CoffeWithHook ()
{

}

void CoffeWithHook::brew ()
{
    printf("Dripping Coffee through filter\n");
}

void CoffeWithHook::addCondiments ()
{
    printf("Adding milk and sugar\n");
}

std::string CoffeWithHook::getUserInput ()
{
    std::string answer;

    std::cout << "Would you like milk and sugar with your coffee (y/n)?" << std::endl;
    std::cin >> answer;

    if (answer.empty()) answer = "no";

    return answer;
}
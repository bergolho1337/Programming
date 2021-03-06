#include "waitress.h"

Waitress::Waitress (PancakeHouseMenu *pancakeMenu, DinerMenu *dinerMenu)
{
    this->pancakeMenu = pancakeMenu;
    this->dinerMenu = dinerMenu;
}

void Waitress::printMenu ()
{
    Iterator *pancakeIterator = this->pancakeMenu->createIterator();
    Iterator *dinerIterator = this->dinerMenu->createIterator();

    printf("MENU\n----------------------------\nBREAKFAST\n");
    printMenuWithIterator(pancakeIterator);
    printf("\nLUNCH\n");
    printMenuWithIterator(dinerIterator);
}

void Waitress::printMenuWithIterator (Iterator *iterator)
{
    while (iterator->hasNext())
    {
        MenuItem *item = (MenuItem*)iterator->next();
        item->print();
    }
}
#ifndef DINER_H
#define DINER_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"
#include "iterator.h"

class DinerMenu
{
private:
    static const int MAX_ITEMS = 6;
    int numberOfItens = 0;
    MenuItem menuItems[MAX_ITEMS];
public:
    DinerMenu ();
    void addItem (std::string name, std::string description, bool vegetarian, double price);
    MenuItem* getMenuItems () { return this->menuItems; }
    int getNumberOfItems () { return this->numberOfItens; }
    DinerMenuIterator* createIterator ();
};


#endif
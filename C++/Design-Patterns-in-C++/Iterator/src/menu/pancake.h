#ifndef PANCAKE_H
#define PANCAKE_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"
#include "iterator.h"

class PancakeHouseMenu
{
private:
    std::vector<MenuItem> menuItems;
public:
    PancakeHouseMenu ();
    void addItem (std::string name, std::string description, bool vegetarian, double price);
    std::vector<MenuItem> getMenuItems () { return this->menuItems; }
    PancakeMenuIterator* createIterator ();
};


#endif
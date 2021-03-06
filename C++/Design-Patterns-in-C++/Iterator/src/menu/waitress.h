#ifndef WAITRESS_H
#define WAITRESS_H

#include <iostream>
#include <string>
#include <vector>

#include "pancake.h"
#include "diner.h"

class Waitress
{
private:
    PancakeHouseMenu *pancakeMenu;
    DinerMenu *dinerMenu;
public:
    Waitress (PancakeHouseMenu *pancakeMenu, DinerMenu *dinerMenu);
    void printMenu ();
private:
    void printMenuWithIterator (Iterator *iterator);
};

#endif
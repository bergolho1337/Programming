#include "pancake.h"

PancakeHouseMenu::PancakeHouseMenu ()
{
    addItem("K&B’s Pancake Breakfast","Pancakes with scrambled eggs, and toast",true,2.99);
    addItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99);
    addItem("Blueberry Pancakes","Pancakes made with fresh blueberries",true,3.49);
    addItem("Waffles","Waffles, with your choice of blueberries or strawberries",true,3.59);
}

void PancakeHouseMenu::addItem (std::string name, std::string description, bool vegetarian, double price)
{
    MenuItem item(name,description,vegetarian,price);
    this->menuItems.push_back(item);
}

PancakeMenuIterator* PancakeHouseMenu::createIterator ()
{
    std::vector<MenuItem> items_vec;
    for (uint32_t i = 0; i < this->menuItems.size(); i++) items_vec.push_back(this->menuItems[i]);
    return new PancakeMenuIterator(items_vec);
}
#include "diner.h"

DinerMenu::DinerMenu ()
{
    addItem("Vegetarian BLT","(Fakin’) Bacon with lettuce & tomato on whole wheat", true, 2.99);
    addItem("BLT","Bacon with lettuce & tomato on whole wheat", false, 2.99);
    addItem("Soup of the day","Soup of the day, with a side of potato salad", false, 3.29);
    addItem("Hotdog","A hot dog, with saurkraut, relish, onions, topped with cheese",false, 3.05);
}

void DinerMenu::addItem (std::string name, std::string description, bool vegetarian, double price)
{
    MenuItem item(name,description,vegetarian,price);
    if (this->numberOfItens >= MAX_ITEMS)
    {
        fprintf(stderr,"[-] ERROR! Sorry, menu is full! Can't add more items!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        this->menuItems[numberOfItens] = item;
        this->numberOfItens++;
    }
}

DinerMenuIterator* DinerMenu::createIterator ()
{
    std::vector<MenuItem> items_vec;
    for (uint32_t i = 0; i < this->numberOfItens; i++) items_vec.push_back(this->menuItems[i]);
    return new DinerMenuIterator(items_vec);
}
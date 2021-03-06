#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class MenuItem
{
private:
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
public:
    MenuItem () { }
    MenuItem (std::string name, std::string description, bool vegetarian, double price)
    {
        this->name = name;
        this->description = description;
        this->vegetarian = vegetarian;
        this->price = price;
    }
    std::string getName () { return this->name; }
    std::string getDescription () { return this->description; }
    bool isVegetarian () { return this->vegetarian; }
    double getPrice () { return this->price; }
    void print ()
    {
        printf("%s %lf %s\n",this->name.c_str(),this->price,this->description.c_str());
    }
};


#endif
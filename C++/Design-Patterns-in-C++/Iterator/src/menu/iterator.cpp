#include "iterator.h"

DinerMenuIterator::DinerMenuIterator(std::vector<MenuItem> items)
{
    this->items = items;
}

bool DinerMenuIterator::hasNext ()
{
    return (position >= this->items.size()) ? false : true;
}

void* DinerMenuIterator::next ()
{
    MenuItem *menuItem = &this->items[position];
    this->position++;
    return (void*)menuItem;
}

PancakeMenuIterator::PancakeMenuIterator(std::vector<MenuItem> items)
{
    this->items = items;
}

bool PancakeMenuIterator::hasNext ()
{
    return (position >= this->items.size()) ? false : true;
}

void* PancakeMenuIterator::next ()
{
    MenuItem *menuItem = &this->items[position];
    this->position++;
    return (void*)menuItem;
}
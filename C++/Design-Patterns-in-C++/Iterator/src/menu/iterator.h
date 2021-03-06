#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"

class Iterator
{
public:
    virtual bool hasNext () = 0;
    virtual void* next () = 0;
};

class DinerMenuIterator : public Iterator
{
private:
    int position = 0;
    std::vector<MenuItem> items;
public:
    DinerMenuIterator (std::vector<MenuItem> items);
    bool hasNext ();
    void* next ();
};

class PancakeMenuIterator : public Iterator
{
private:
    int position = 0;
    std::vector<MenuItem> items;
public:
    PancakeMenuIterator (std::vector<MenuItem> items);
    bool hasNext ();
    void* next ();
};

#endif
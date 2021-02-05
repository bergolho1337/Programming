#include "duck.h"

Duck::Duck ()
{
    // Constructor
}

MallardDuck::MallardDuck ()
{

}

void MallardDuck::fly ()
{
    printf("I am flying!\n");
}

void MallardDuck::quack ()
{
    printf("QUACK!\n");
}

void MallardDuck::display ()
{
    printf("I am a Mallard duck!\n");
}

AdapterTurkey::AdapterTurkey (Turkey *turkey)
{
    this->turkey = turkey;
}

void AdapterTurkey::fly ()
{
    for (uint32_t i = 0; i < 5; i++)
        this->turkey->fly();
}

void AdapterTurkey::quack ()
{
    this->turkey->gobble();
}

void AdapterTurkey::display ()
{
    printf("I am Duck! (but actually I am a turkey)\n");
}
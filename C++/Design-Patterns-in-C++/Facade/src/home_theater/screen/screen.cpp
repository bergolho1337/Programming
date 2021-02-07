#include "screen.h"

Screen::Screen ()
{
    this->position = false;
}

void Screen::up ()
{
    printf("[Screen] UP!\n");
    this->position = true;
}

void Screen::down ()
{
    printf("[Screen] DOWN!\n");
    this->position = false;
}
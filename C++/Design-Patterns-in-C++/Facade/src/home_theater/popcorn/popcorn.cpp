#include "popcorn.h"

PopcornPopper::PopcornPopper ()
{

}

void PopcornPopper::on ()
{
    printf("[PopcornPopper] ON!\n");
    this->is_on = true;
    this->num_popcorn = 0;
}

void PopcornPopper::off ()
{
    printf("[PopcornPopper] OFF!\n");
    this->is_on = false;
}

void PopcornPopper::pop ()
{
    printf("[PopcornPopper] Popcorn ready!\n");
    this->num_popcorn = 30;
}
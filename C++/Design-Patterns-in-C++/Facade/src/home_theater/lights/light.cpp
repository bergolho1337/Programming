#include "light.h"

TheaterLight::TheaterLight ()
{

}

void TheaterLight::on ()
{
    printf("[TheaterLight] ON!\n");
    this->is_on = true;
}

void TheaterLight::off ()
{
    printf("[TheaterLight] OFF!\n");
    this->is_on = false;
}
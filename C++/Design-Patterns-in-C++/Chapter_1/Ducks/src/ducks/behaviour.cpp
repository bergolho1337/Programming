#include "behaviour.h"

void FlyWithWings::fly ()
{
    printf("I can fly with wings!\n");    
}

void FlyNoWay::fly ()
{
    printf("I cannot fly in any way!\n");
}

void FlyRocketPowered::fly ()
{
    printf("I am flying with a rocket!\n");
}

void Quack::quack ()
{
    printf("QUACK!\n");
}

void Squeak::quack ()
{
    printf("SQUEAK!\n");
}

void MuteQuack::quack ()
{
    printf("######\n");
}
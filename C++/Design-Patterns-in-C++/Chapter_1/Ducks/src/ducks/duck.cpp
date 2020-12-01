#include "duck.h"

Duck::Duck ()
{
    // Constructor
}

void Duck::swim ()
{
    printf("I can swim!\n");
}

void Duck::performFly ()
{
    if (fly_behaviour) fly_behaviour->fly();
}

void Duck::performQuack ()
{
    if (quack_behaviour) quack_behaviour->quack();
}

void Duck::setFlyBehaviour (FlyBehaviour *fb)
{
    this->fly_behaviour = fb;
}

void Duck::setQuackBehaviour (QuackBehaviour *qb)
{
    this->quack_behaviour = qb;
}

MallardDuck::MallardDuck ()
{
    this->quack_behaviour = new Quack;
    this->fly_behaviour = new FlyWithWings;
}

void MallardDuck::display ()
{
    printf("I am a Mallard duck!\n");
}

RedheadDuck::RedheadDuck ()
{
    this->quack_behaviour = new Squeak;
    this->fly_behaviour = new FlyWithWings;
}

void RedheadDuck::display ()
{
    printf("I am a Redhead duck!\n");
}

RubberDuck::RubberDuck ()
{
    this->quack_behaviour = new Quack;
    this->fly_behaviour = NULL;
}

void RubberDuck::display ()
{
    printf("I am a Rubber duck!\n");
}

DecoyDuck::DecoyDuck ()
{
    this->quack_behaviour = NULL;
    this->fly_behaviour = NULL;
}

void DecoyDuck::display ()
{
    printf("I am a Decoy duck!\n");
}

ModelDuck::ModelDuck ()
{
    this->quack_behaviour = new Quack;
    this->fly_behaviour = new FlyNoWay;
}

void ModelDuck::display ()
{
    printf("I am a Model duck!\n");
}

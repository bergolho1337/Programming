#ifndef GARAGEDOOR_H
#define GARAGEDOOR_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "../command.h"

class GarageDoor
{
private:
    int state;   // 0 = close, 1 = open
    bool light_is_on;
public:
    GarageDoor () { this->state = 0; this->light_is_on = false; }
    void up () { this->state = 1; }
    void down () { this->state = 0; }
    void stop () {  };
    void lightOn () { this->light_is_on = true; }
    void lightOff () { this->light_is_on = false; }
};

class GarageDoorUpCommand : public Command
{
private:
    GarageDoor *door;
public:
    GarageDoorUpCommand (GarageDoor *door) { this->door = door; }
    void execute () { printf("Garage door is open!\n"); }
    void undo () { door->down(); }
    std::string classname () { return "GarageDoorUpCommand"; }
};

class GarageDoorDownCommand : public Command
{
private:
    GarageDoor *door;
public:
    GarageDoorDownCommand (GarageDoor *door) { this->door = door; }
    void execute () { printf("Garage door is close!\n"); }
    void undo () { door->up(); }
    std::string classname () { return "GarageDoorDownCommand"; }
};

#endif

#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "../command.h"

class Light
{
private:
    bool is_on;
    std::string placename;
public:
    Light (std::string placename) { this->is_on = false; this->placename = placename; };
    std::string getPlacename () { return this->placename; }
    void on () { this->is_on = true; };
    void off () { this->is_on = false; }
};

class LightOnCommand : public Command
{
private:
    Light *light;
public:
    LightOnCommand (Light *light) { this->light = light; };
    void execute () { printf("%s light is on!\n", light->getPlacename().c_str()); this->light->on(); };
    void undo () { printf("%s light is off!\n", light->getPlacename().c_str()); this->light->off(); };
    std::string classname () { return "LightOnCommand"; }
};

class LightOffCommand : public Command
{
private:
    Light *light;
public:
    LightOffCommand (Light *light) { this->light = light; };
    void execute () { printf("%s light is off!\n", light->getPlacename().c_str()); this->light->off(); };
    void undo () { printf("%s light is on!\n", light->getPlacename().c_str()); this->light->on(); };
    std::string classname () { return "LightOffCommand"; }
};

#endif 

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cstdio>

// Abstract class - Interface
class Command
{
public:
    virtual void execute () = 0;
    virtual void undo () = 0;
    virtual std::string classname () = 0;
};

// Null class
class NoCommand : public Command
{
public:
    NoCommand () { }
    void execute () { printf("Null comand\n"); }
    void undo () { }
    std::string classname () { return "NoCommand"; }
};

class MacroCommand : public Command
{
private:
    std::vector<Command*> commands;
public:
    MacroCommand (std::vector<Command*> commands)
    {
        this->commands = commands;
    }
    void execute ()
    {
        for (uint32_t i = 0; i < this->commands.size(); i++)
            this->commands[i]->execute();
    }
    void undo () 
    { 
        for (uint32_t i = 0; i < this->commands.size(); i++)
            this->commands[i]->undo();
    }
    std::string classname () { return "MacroCommand"; }
};

#endif
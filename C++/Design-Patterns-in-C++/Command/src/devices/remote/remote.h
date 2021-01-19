#ifndef REMOTE_H
#define REMOTE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "../light/light.h"
#include "../ceiling_fan/ceiling_fan.h"
#include "../garage_door/garage_door.h"
#include "../stereo/stereo.h"

class SimpleRemoteControl
{
private:
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
public:
    const uint32_t NUM_SLOTS = 7;

    SimpleRemoteControl ();
    void setCommand (const uint32_t slot, Command *onCommand, Command *offCommand);
    void onButtomWasPressed (const uint32_t slot);
    void offButtomWasPressed (const uint32_t slot); 
    void toString ();
};

class RemoteControlWithUndo
{
private:
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
    Command *undoCommand;
public:
    const uint32_t NUM_SLOTS = 7;

    RemoteControlWithUndo ();
    void setCommand (const uint32_t slot, Command *onCommand, Command *offCommand);
    void onButtomWasPressed (const uint32_t slot);
    void offButtomWasPressed (const uint32_t slot); 
    void undoBottomWasPressed ();
    void toString ();
};

#endif 

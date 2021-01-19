#include "remote.h"

SimpleRemoteControl::SimpleRemoteControl ()
{
    Command *noCommand = new NoCommand();

    onCommands.assign(NUM_SLOTS,noCommand);
    offCommands.assign(NUM_SLOTS,noCommand);
}

void SimpleRemoteControl::setCommand (const uint32_t slot, Command *onCommand, Command *offCommand)
{
    this->onCommands[slot] = onCommand;
    this->offCommands[slot] = offCommand;
}

void SimpleRemoteControl::onButtomWasPressed (const uint32_t slot)
{
    this->onCommands[slot]->execute();
}

void SimpleRemoteControl::offButtomWasPressed (const uint32_t slot)
{
    this->offCommands[slot]->execute();
}

void SimpleRemoteControl::toString ()
{
   printf("\n------ Remote Control -------\n");
   for (uint32_t i = 0; i < NUM_SLOTS; i++)
   {
       printf("[slot %u]\t%20s\t%20s\n",i+1,onCommands[i]->classname().c_str(),offCommands[i]->classname().c_str());
   }
}

RemoteControlWithUndo::RemoteControlWithUndo ()
{
    Command *noCommand = new NoCommand();

    onCommands.assign(NUM_SLOTS,noCommand);
    offCommands.assign(NUM_SLOTS,noCommand);
    undoCommand = noCommand;
}

void RemoteControlWithUndo::setCommand (const uint32_t slot, Command *onCommand, Command *offCommand)
{
    this->onCommands[slot] = onCommand;
    this->offCommands[slot] = offCommand;
}

void RemoteControlWithUndo::onButtomWasPressed (const uint32_t slot)
{
    this->onCommands[slot]->execute();
    undoCommand = onCommands[slot];     // Save the last command in the undo pointer
}

void RemoteControlWithUndo::offButtomWasPressed (const uint32_t slot)
{
    this->offCommands[slot]->execute();
    undoCommand = offCommands[slot];     // Save the last command in the undo pointer
}

void RemoteControlWithUndo::undoBottomWasPressed ()
{
    undoCommand->undo();
}

void RemoteControlWithUndo::toString ()
{
   printf("\n------ Remote Control -------\n");
   for (uint32_t i = 0; i < NUM_SLOTS; i++)
   {
       printf("[slot %u]\t%20s\t%20s\n",i+1,onCommands[i]->classname().c_str(),offCommands[i]->classname().c_str());
   }
   printf("[undo] %s\n",undoCommand->classname().c_str());
}
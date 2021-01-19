#ifndef CEILINGFAN_H
#define CEILINGFAN_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "../command.h"

class CeilingFan
{
public:
    const int OFF = 0;
    const int LOW = 1;
    const int MEDIUM = 2;
    const int HIGH = 3;
private:
    int speed;
    std::string placename;
public:
    CeilingFan (std::string placename) { this->speed = OFF; this->placename = placename; };
    std::string getPlacename () { return this->placename; }
    int getSpeed () { return this->speed; }
    void off () { this->speed = 0; printf("%s ceiling fan is OFF!\n", this->placename.c_str()); };
    void low () { this->speed = 1; printf("%s ceiling fan is LOW!\n", this->placename.c_str()); };
    void medium () { this->speed = 2; printf("%s ceiling fan is MEDIUM!\n", this->placename.c_str()); };
    void high () { this->speed = 3; printf("%s ceiling fan is HIGH!\n", this->placename.c_str()); };
};

class CeilingFanHighCommand : public Command
{
private:
    int prev_speed;
    CeilingFan *fan;
public:
    CeilingFanHighCommand (CeilingFan *fan) { this->fan = fan; };
    void execute () 
    { 
        this->prev_speed = fan->getSpeed();
        this->fan->high(); 
    }
    void undo () 
    {  
        if (prev_speed == this->fan->OFF) this->fan->off();
        else if (prev_speed == this->fan->LOW) this->fan->low();
        else if (prev_speed == this->fan->MEDIUM) this->fan->medium();
        else if (prev_speed == this->fan->HIGH) this->fan->high();
        else
        {
            fprintf(stderr,"[-] ERROR! Invalid ceiling fan speed!\n");
            exit(EXIT_FAILURE);
        }
    }
    std::string classname () { return "CeilingFanHighCommand"; }
};

class CeilingFanMediumCommand : public Command
{
private:
    int prev_speed;
    CeilingFan *fan;
public:
    CeilingFanMediumCommand (CeilingFan *fan) { this->fan = fan; };
    void execute () 
    { 
        this->prev_speed = fan->getSpeed();
        this->fan->medium(); 
    }
    void undo () 
    {  
        if (prev_speed == this->fan->OFF) this->fan->off();
        else if (prev_speed == this->fan->LOW) this->fan->low();
        else if (prev_speed == this->fan->MEDIUM) this->fan->medium();
        else if (prev_speed == this->fan->HIGH) this->fan->high();
        else
        {
            fprintf(stderr,"[-] ERROR! Invalid ceiling fan speed!\n");
            exit(EXIT_FAILURE);
        }
    }
    std::string classname () { return "CeilingFanMediumCommand"; }
};

class CeilingFanLowCommand : public Command
{
private:
    int prev_speed;
    CeilingFan *fan;
public:
    CeilingFanLowCommand (CeilingFan *fan) { this->fan = fan; };
    void execute () 
    { 
        this->prev_speed = fan->getSpeed();
        this->fan->low(); 
    }
    void undo () 
    {  
        if (prev_speed == this->fan->OFF) this->fan->off();
        else if (prev_speed == this->fan->LOW) this->fan->low();
        else if (prev_speed == this->fan->MEDIUM) this->fan->medium();
        else if (prev_speed == this->fan->HIGH) this->fan->high();
        else
        {
            fprintf(stderr,"[-] ERROR! Invalid ceiling fan speed!\n");
            exit(EXIT_FAILURE);
        }
    }
    std::string classname () { return "CeilingFanLowCommand"; }
};

class CeilingFanOffCommand : public Command
{
private:
    int prev_speed;
    CeilingFan *fan;
public:
    CeilingFanOffCommand (CeilingFan *fan) { this->fan = fan; };
    void execute () 
    { 
        this->prev_speed = fan->getSpeed(); 
        this->fan->off(); 
    }
    void undo () 
    {  
        if (prev_speed == this->fan->OFF) this->fan->off();
        else if (prev_speed == this->fan->LOW) this->fan->low();
        else if (prev_speed == this->fan->MEDIUM) this->fan->medium();
        else if (prev_speed == this->fan->HIGH) this->fan->high();
        else
        {
            fprintf(stderr,"[-] ERROR! Invalid ceiling fan speed!\n");
            exit(EXIT_FAILURE);
        }
    }
    std::string classname () { return "CeilingFanOffCommand"; }
};

#endif 

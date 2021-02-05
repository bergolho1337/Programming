#ifndef TURKEY_H
#define TURKEY_H

#include <iostream>
#include <cstdio>

// Super class
class Turkey 
{
public:
    Turkey ();
    virtual void fly () = 0;
    virtual void gobble () = 0;
    virtual void display () = 0;
};

// Types of turkey
class WildTurkey : public Turkey
{
public:
    WildTurkey ();
    void fly ();
    void gobble ();
    void display ();
};

#endif

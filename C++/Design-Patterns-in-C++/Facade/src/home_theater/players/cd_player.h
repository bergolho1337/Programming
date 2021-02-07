#ifndef CDPLAYER_H
#define CDPLAYER_H

#include <iostream>
#include <cstdio>

#include "amplifier.h"

class CDPlayer
{
private:
    Amplifier *amp;
    bool is_on;
public:
    CDPlayer (Amplifier *amp);
    void on ();
    void off ();
    void play ();
    void pause ();
    void stop ();
    void eject ();
};

#endif 

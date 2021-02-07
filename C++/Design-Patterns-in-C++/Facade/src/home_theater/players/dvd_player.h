#ifndef DVDPLAYER_H
#define DVDPLAYER_H

#include <iostream>
#include <cstdio>

#include "amplifier.h"

class DVDPlayer
{
private:
    Amplifier *amp;
    bool is_on;
    bool is_surround;
public:
    DVDPlayer (Amplifier *amp);
    void on ();
    void off ();
    void play (std::string name);
    void pause ();
    void stop ();
    void eject ();
    void setSurroundAudio ();
    void setTwoChannelAudio ();
};

#endif 

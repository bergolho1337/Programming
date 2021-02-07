#ifndef THEATER_H
#define THEATER_H

#include <iostream>
#include <cstdio>

#include "players/amplifier.h"
#include "players/cd_player.h"
#include "players/dvd_player.h"
#include "lights/light.h"
#include "popcorn/popcorn.h"
#include "screen/screen.h"

class HomeTheaterFacade
{
private:
    Amplifier *amp;
    //Tuner *tuner;
    DVDPlayer *dvd;
    CDPlayer *cd;
    //Projector *projector;
    TheaterLight *light;
    Screen *screen;
    PopcornPopper *popper;
public:
    HomeTheaterFacade (Amplifier *amp, TheaterLight *light, PopcornPopper *popper, Screen *screen,\
                        CDPlayer *cd, DVDPlayer *dvd);
    void watchMovie (std::string name);
    void endMovie ();
};

#endif /* __STOPWATCH_H */

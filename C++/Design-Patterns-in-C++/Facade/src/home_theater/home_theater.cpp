#include "home_theater.h"

HomeTheaterFacade::HomeTheaterFacade (Amplifier *amp, TheaterLight *light, PopcornPopper *popper, Screen *screen,\
                                    CDPlayer *cd, DVDPlayer *dvd)
{
    this->amp = amp;
    this->cd = cd;
    this->dvd = dvd;
    this->light = light;
    this->popper = popper;
    this->screen = screen;
}

void HomeTheaterFacade::watchMovie (std::string name)
{
    popper->on();
    popper->pop();

    light->on();

    screen->down();

    amp->on();
    amp->setDvd(dvd);
    amp->setSurroundSound();
    amp->setVolume(5);

    dvd->on();
    dvd->play(name);
}

void HomeTheaterFacade::endMovie ()
{
    popper->off();

    light->off();

    screen->up();

    amp->off();

    dvd->stop();
    dvd->eject();
    dvd->off();
}
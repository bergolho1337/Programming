// ---------------------------------------------------------------------------------------------
// Facade design pattern:
// Provides a unified interface to a set of interfaces in a subsytem. Facade defines a higher
// level interface that makes the subsystem easier to use.
// ---------------------------------------------------------------------------------------------

#include <iostream>
#include "home_theater/home_theater.h"

int main (int argc, char *argv[])
{
	Amplifier *amp = new Amplifier();
	CDPlayer *cd_player = new CDPlayer(amp);
	DVDPlayer *dvd_player = new DVDPlayer(amp);
	TheaterLight *light = new TheaterLight();
	PopcornPopper *popper = new PopcornPopper();
	Screen *screen = new Screen();

	HomeTheaterFacade *home_theater = new HomeTheaterFacade(amp,light,popper,screen,cd_player,dvd_player);
	home_theater->watchMovie("Raiders of the Lost Ark");
	home_theater->endMovie();

	return 0;
}

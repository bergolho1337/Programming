#include "dvd_player.h"

DVDPlayer::DVDPlayer (Amplifier *amp)
{
    this->amp = amp;
    this->is_on = false;
    this->is_surround = false;
}

void DVDPlayer::on ()
{
    printf("[DVDPlayer] ON!\n");
    this->is_on = true;
}

void DVDPlayer::off ()
{
    printf("[DVDPlayer] OFF!\n");
    this->is_on = false;
}

void DVDPlayer::play (std::string name)
{
    printf("[DVDPlayer] Playing '%s'!\n",name.c_str());
}

void DVDPlayer::pause ()
{
    printf("[DVDPlayer] PAUSE!\n");
}

void DVDPlayer::stop ()
{
    printf("[DVDPlayer] STOP!\n");
}

void DVDPlayer::eject ()
{
    printf("[DVDPlayer] EJECT!\n");
}

void DVDPlayer::setSurroundAudio ()
{
    this->is_surround = true;
}

void DVDPlayer::setTwoChannelAudio ()
{
    this->is_surround = false;
}
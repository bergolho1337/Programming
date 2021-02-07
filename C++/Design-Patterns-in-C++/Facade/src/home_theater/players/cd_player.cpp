#include "cd_player.h"

CDPlayer::CDPlayer (Amplifier *amp)
{
    this->amp = amp;
    this->is_on = false;
}

void CDPlayer::on ()
{
    printf("[CDPlayer] ON!\n");
    this->is_on = true;
}

void CDPlayer::off ()
{
    printf("[CDPlayer] OFF!\n");
    this->is_on = false;
}

void CDPlayer::play ()
{
    printf("[CDPlayer] PLAY!\n");
}

void CDPlayer::pause ()
{
    printf("[CDPlayer] PAUSE!\n");
}

void CDPlayer::stop ()
{
    printf("[CDPlayer] STOP!\n");
}

void CDPlayer::eject ()
{
    printf("[CDPlayer] EJECT!\n");
}

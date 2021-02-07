#include "amplifier.h"

Amplifier::Amplifier ()
{
    this->is_on = false;
    this->is_surround = false;
    this->volume = 0;
}

void Amplifier::on ()
{
    printf("[Amplifier] ON!\n");
    this->is_on = true;
}

void Amplifier::off ()
{
    printf("[Amplifier] OFF!\n");
    this->is_on = false;
}

void Amplifier::setStereoSound ()
{
    printf("[Amplifier] Stereo sound\n");
    this->is_surround = false;
}

void Amplifier::setSurroundSound ()
{
    printf("[Amplifier] Surround sound\n");
    this->is_surround = true;
}

void Amplifier::setVolume (const int volume)
{
    printf("[Amplifier] Volume = %d\n",volume);
    this->volume = volume;
}

void Amplifier::setCd (CDPlayer *cd)
{
    this->cd_player = cd;
}

void Amplifier::setDvd (DVDPlayer *dvd)
{
    printf("[Amplifier] DVD player ready!\n");
    this->dvd_player = dvd;
}

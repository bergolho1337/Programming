#ifndef AMPLIFIER_H
#define AMPLIFIER_H

#include <iostream>
#include <cstdio>

class CDPlayer;
class DVDPlayer;

class Amplifier
{
private:
    bool is_on;
    bool is_surround;
    int volume;
    CDPlayer *cd_player;
    DVDPlayer *dvd_player;
    //Tuner *tuner;
public:
    Amplifier ();
    void on ();
    void off ();
    void setCd (CDPlayer *cd);
    void setDvd (DVDPlayer *dvd);
    //void setTuner (Tuner *tuner);
    void setSurroundSound ();
    void setStereoSound ();
    void setVolume (const int volume);
};

#endif 

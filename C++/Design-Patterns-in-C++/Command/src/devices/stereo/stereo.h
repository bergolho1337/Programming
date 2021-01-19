#ifndef STEREO_H
#define STEREO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

#include "../command.h"

class Music
{
private:
    std::string name;
    std::string singer;
public:
    Music (std::string name, std::string singer) { this->name = name; this->singer = singer; }
    void print () { printf("[Music] Name = %s, Singer = %s\n", this->name.c_str(),this->singer.c_str()); }
};

class CD
{
private:
    std::string title;
    std::vector<Music> tracklist;
public:
    CD (std::string title, std::string filename)
    {
        this->title = title;
        std::ifstream in(filename);
        if (!in)
        {
            fprintf(stderr,"[-] ERROR! Could not read CD '%s'\n",filename.c_str());
            exit(EXIT_FAILURE);
        }
        std::string str;
        getline(in,str);
        uint32_t num_tracks = std::stoi(str);
        for (uint32_t i = 0; i < num_tracks; i++)
        {
            std::string title, singer;
            getline(in,title);
            getline(in,singer);
            Music music(title,singer);
            tracklist.push_back(music);
        }
        in.close();
    }
    std::string getTitle () { return this->title; }
    void print ()
    {
        printf("------- Stereo ---------\n");
        printf("Title: %s\n",this->title.c_str());
        printf("Number of tracks: %u\n",this->tracklist.size());
        for (uint32_t i = 0; i < this->tracklist.size(); i++)
            this->tracklist[i].print();
        printf("------------------------\n");
    } 
};

class Stereo
{
private:
    bool is_on;
    CD *cd;
    //DVD *dvd;
    //Radio *radio;
    double volume;
public:
    Stereo () { this->is_on = false; }
    void on () { this->is_on = true; printf("Stereo is on!\n"); }
    void off () { this->is_on = false; printf("Stereo is off!\n"); }
    void stop () {  };
    void setCD (CD *cd) { this->cd = cd; }
    void setVolume (const double volume) { this->volume = volume; }
};

class StereoOnCommand : public Command
{
private:
    Stereo *stereo;
public:
    StereoOnCommand (Stereo *stereo) { this->stereo = stereo; }
    void execute () 
    { 
        stereo->on();
        stereo->setVolume(11);
    }
    void undo () { stereo->off(); }
    std::string classname () { return "StereoOnCommand"; }
};

class StereoOnWithCDCommand : public Command
{
private:
    Stereo *stereo;
    CD *cd;
public:
    StereoOnWithCDCommand (Stereo *stereo, CD *cd) { this->stereo = stereo; this->cd = cd; }
    void changeCD (CD *cd) 
    { 
        printf("[Stereo] Changing cd from '%s' to '%s'!\n\n",this->cd->getTitle().c_str(),cd->getTitle().c_str());
        this->cd = cd;
    }
    void execute () 
    { 
        stereo->on();
        stereo->setCD(cd);
        stereo->setVolume(11);

        printf("[Stereo] Now playing '%s' ...\n",cd->getTitle().c_str());
        cd->print();
        printf("\n");
    }
    void undo () { stereo->off(); }
    std::string classname () { return "StereoOnWithCDCommand"; }
};

class StereoOffCommand : public Command
{
private:
    Stereo *stereo;
public:
    StereoOffCommand (Stereo *stereo) { this->stereo = stereo; }
    void execute () { stereo->off(); }
    void undo () { stereo->on(); }
    std::string classname () { return "StereoOffCommand"; }
};

#endif

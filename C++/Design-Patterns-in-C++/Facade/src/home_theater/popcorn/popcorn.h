#ifndef POPCORN_H
#define POPCORN_H

#include <iostream>
#include <cstdio>

class PopcornPopper
{
private:
    bool is_on;
    int num_popcorn;
public:
    PopcornPopper ();
    void on ();
    void off ();
    void pop ();
};

#endif /* __STOPWATCH_H */

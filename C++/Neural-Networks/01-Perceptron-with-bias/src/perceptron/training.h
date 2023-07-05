#ifndef TRAINING_H
#define TRAINING_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>

#include "../utils/utils.h"

#define TRAINING_SET_SIZE 200               // Default training set size
#define LEARNING_RATE 0.1                   // The LEARNING_RATE is a fixed parameter that controls how much we are going to tune the weigths (KEEP IT SMALL TO AVOID BOUNCING OVER THE DOMAIN)

class Training_Set
{
private:
    std::vector<Point> t_set;
    
    double classify_function (Point p);
    void draw_points ();
    void draw_line ();
public:
    static constexpr double m = -0.3;
    static constexpr double b = -0.2;

    Training_Set ();
    Training_Set (const uint32_t n);
    void classify ();
    void print ();
    void draw ();

    std::vector<Point> get_training_set ()
    {
        return t_set;
    }
};

#endif
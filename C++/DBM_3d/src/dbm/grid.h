#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define EMPTY '-'
#define CANDIDATE 'C'
#define FILLED 'F'

class Grid
{
private:
    uint32_t n;                                 // Size of the grid
    double h;                                   // Grid discretization 
    char *grid;                                 // Multidimensional array to store the 3d grid
public:
    Grid (const uint32_t n, const double h);
    ~Grid ();
    void fill_position (const uint32_t i, const uint32_t j, const uint32_t k, const char value);
    bool update_position (uint32_t &i, uint32_t &j, uint32_t &k);
    bool search_position (const uint32_t i, const uint32_t j, const uint32_t k, const char value);
    uint32_t count_number_cells (std::vector<uint32_t> &ids, const char key);
    uint32_t get_id (const uint32_t i, const uint32_t j, const uint32_t k);
    uint32_t get_size () { return this->n; }
    double get_discretization () { return this->h; }
    void print ();
};

#endif
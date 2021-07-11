#ifndef DBM_H
#define DBM_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "grid.h"
#include "cell.h"

class DBM
{
private:
    uint32_t max_iter;                          // Maximum number of iterations
    double eta;                                 // Model parameter
    std::vector<Cell> the_pattern;              // Current pattern of the tree
    std::vector<Cell> the_candidates;           // Candidate list
    Grid *the_grid = NULL;                      // Grid data
public:
    DBM (const uint32_t n, const uint32_t max_iter, const double h, const double eta);
    ~DBM ();
    void set_root (const uint32_t i, const uint32_t j, const uint32_t k);
    void set_neighbours ();
    void set_candidate (const uint32_t i, const uint32_t j, const uint32_t k);
    void set_potential ();
    void run ();
    Cell select_candidate ();
    void update_neighbours (Cell cell);
    void update_candidate (const uint32_t i, const uint32_t j, const uint32_t k);
    void print_grid ();
    void print ();
    void write_to_vtk (const uint32_t iter);
};


#endif
#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils/utils.h"

class Cell
{
private:
	//const double R1 = H/2;
	uint32_t id;                // Index
	uint32_t pos[3];			// Position (i,j,k)
    double coord[3];            // Coordinates (x,y,z)
	double value;		        // Eletrostatic potential
	double phi_eta;
	double p;
	double partial_sum;
public:
	Cell (const uint32_t i, const uint32_t j, const uint32_t k, const uint32_t n, const double h);
	void compute_potential (std::vector<Cell> the_pattern, const double h);
    void update_potential (Cell new_cell, const double h);
    void compute_phi_eta (const double min_value, const double max_value, const double eta);
    void compute_p (const double sum_phi_eta);
    double* get_coordinates ();
    uint32_t* get_position ();
    double get_value ();
    double get_phi_eta ();
    double get_p ();
    double get_partial_sum ();
    void set_partial_sum (const double partial_sum);
    void print ();
};

#endif
#include "cell.h"

Cell::Cell (const uint32_t i, const uint32_t j, const uint32_t k, const uint32_t n, const double h)
{
    this->id = (k*n*n)+(i*n+j);
    this->pos[0] = i;
    this->pos[1] = j;
    this->pos[2] = k;
    this->coord[0] = i*h;
    this->coord[1] = j*h;
    this->coord[2] = k*h;
    this->value = 0;
}

double* Cell::get_coordinates ()
{
    return this->coord;
}

double Cell::get_value ()
{
    return this->value;
}

double Cell::get_phi_eta ()
{
    return this->phi_eta;
}

double Cell::get_p ()
{
    return this->p;
}

uint32_t* Cell::get_position ()
{
    return this->pos;
}

double Cell::get_partial_sum ()
{
    return this->partial_sum;
}

void Cell::set_partial_sum (const double partial_sum)
{
    this->partial_sum = partial_sum;
}

void Cell::compute_potential (std::vector<Cell> the_pattern, const double h)
{
    this->value = 0.0;
    double R1 = h/2.0;
    
    double *p1 = this->coord;
    for (uint32_t i = 0; i < the_pattern.size(); i++)
    {
        double *p2 = the_pattern[i].get_coordinates();
        double r_ij = euclidean_norm(p1[0],p1[1],p1[2],p2[0],p2[1],p2[2]);

        this->value += (1.0 - (R1/r_ij));	
    }
}

void Cell::update_potential (Cell new_cell, const double h)
{
    double R1 = h/2.0;

    double *p1 = this->coord;
    double *p2 = new_cell.get_coordinates();
    
    double r_it = euclidean_norm(p1[0],p1[1],p1[2],p2[0],p2[1],p2[2]);
    this->value += (1.0 - (R1/r_it));
}

void Cell::compute_phi_eta (const double min_value, const double max_value, const double eta)
{
    this->phi_eta = pow( (this->value-min_value)/(max_value-min_value),eta );
}

void Cell::compute_p (const double sum_phi_eta)
{
    this->p = this->phi_eta / sum_phi_eta;
}

void Cell::print ()
{
    printf("[Cell %u] --> pos=(%u,%u,%u), coord=(%g,%g,%g), Potential = %g\n",this->id,\
                                                                    this->pos[0],this->pos[1],this->pos[2],\
                                                                    this->coord[0],this->coord[1],this->coord[2],\
                                                                    this->value);
}
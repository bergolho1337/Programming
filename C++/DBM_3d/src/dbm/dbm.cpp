#include "dbm.h"

DBM::DBM (const uint32_t n, const uint32_t max_iter, const double h, const double eta)
{
    this->max_iter = max_iter;
    this->eta = eta;
    this->the_grid = new Grid(n,h);
}

DBM::~DBM ()
{
    if (this->the_grid)
        delete this->the_grid;
}

void DBM::set_root (const uint32_t i, const uint32_t j, const uint32_t k)
{
    uint32_t n = this->the_grid->get_size();
    double h = this->the_grid->get_discretization();
    
    Cell root(i,j,k,n,h);
    this->the_pattern.push_back(root);
    this->the_grid->fill_position(i,j,k,FILLED);
}

void DBM::set_neighbours ()
{
    for (uint32_t i = 0; i < the_pattern.size(); i++)
	{
        uint32_t *pos = the_pattern[i].get_position();

		// North
		set_candidate(pos[0]-1,pos[1],pos[2]);
		// Northeast
		set_candidate(pos[0]-1,pos[1]+1,pos[2]);
		// East
		set_candidate(pos[0],pos[1]+1,pos[2]);
        // Southeast
		set_candidate(pos[0]+1,pos[1]+1,pos[2]);
        // South
		set_candidate(pos[0]+1,pos[1],pos[2]);
        // Southwest
		set_candidate(pos[0]+1,pos[1]-1,pos[2]);
        // West
		set_candidate(pos[0],pos[1]-1,pos[2]);
        // Northwest
		set_candidate(pos[0]-1,pos[1]-1,pos[2]);

        // North
		set_candidate(pos[0]-1,pos[1],pos[2]+1);
		// Northeast
		set_candidate(pos[0]-1,pos[1]+1,pos[2]+1);
		// East
		set_candidate(pos[0],pos[1]+1,pos[2]+1);
        // Southeast
		set_candidate(pos[0]+1,pos[1]+1,pos[2]+1);
        // South
		set_candidate(pos[0]+1,pos[1],pos[2]+1);
        // Southwest
		set_candidate(pos[0]+1,pos[1]-1,pos[2]+1);
        // West
		set_candidate(pos[0],pos[1]-1,pos[2]+1);
        // Northwest
		set_candidate(pos[0]-1,pos[1]-1,pos[2]+1);
        // Front
        set_candidate(pos[0],pos[1],pos[2]+1);

        // North
		set_candidate(pos[0]-1,pos[1],pos[2]-1);
		// Northeast
		set_candidate(pos[0]-1,pos[1]+1,pos[2]-1);
		// East
		set_candidate(pos[0],pos[1]+1,pos[2]-1);
        // Southeast
		set_candidate(pos[0]+1,pos[1]+1,pos[2]-1);
        // South
		set_candidate(pos[0]+1,pos[1],pos[2]-1);
        // Southwest
		set_candidate(pos[0]+1,pos[1]-1,pos[2]-1);
        // West
		set_candidate(pos[0],pos[1]-1,pos[2]-1);
        // Northwest
		set_candidate(pos[0]-1,pos[1]-1,pos[2]-1);
        // Back
        set_candidate(pos[0],pos[1],pos[2]-1);
	}
	
	set_potential();
}

void DBM::set_candidate (const uint32_t i, const uint32_t j, const uint32_t k)
{
    uint32_t pos[3];
    pos[0] = i;
    pos[1] = j;
    pos[2] = k;
    
    Grid *the_grid = this->the_grid;
    uint32_t n = the_grid->get_size();
    double h = the_grid->get_discretization();
    bool sucess = the_grid->update_position(pos[0],pos[1],pos[2]);
    if (sucess)
    {
        the_grid->fill_position(pos[0],pos[1],pos[2],CANDIDATE);
	
        Cell cell(pos[0],pos[1],pos[2],n,h);
        the_candidates.push_back(cell);
    }
}

void DBM::set_potential ()
{
    double h = this->the_grid->get_discretization();
    for (uint32_t i = 0; i < the_candidates.size(); i++)
		the_candidates[i].compute_potential(the_pattern,h);
}

Cell DBM::select_candidate ()
{
    uint32_t result_index = 0;
    double eta = this->eta;

	// Business rule to select a cell
	// 1) Get the min/max potential from the candidate list
	double min_value = __DBL_MAX__, max_value = __DBL_MIN__;
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
        double value = the_candidates[i].get_value();
		if (value < min_value) min_value = value;
		if (value > max_value) max_value = value;
	}
	// 2) Calculate phi_i_eta for each candidate cell
	double sum_phi_eta = 0.0;
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
		the_candidates[i].compute_phi_eta(min_value,max_value,eta);
        double phi_eta = the_candidates[i].get_phi_eta();
		sum_phi_eta += phi_eta;
	}
	// 3) Calculate p_i for each candidate cell
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
		the_candidates[i].compute_p(sum_phi_eta);
	}
	// 4) Compute the partial sum from the p_i values
	double partial_sum = 0.0;
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
        double p = the_candidates[i].get_p();
		partial_sum += p;
		the_candidates[i].set_partial_sum(partial_sum);
	}
	// 5) Get a random number in the interval: [0, partial_sum] --> partial_sum = 1 at the end
	bool sucess = false;
	while (!sucess)
	{
		double R = (double)rand() / (double)RAND_MAX;
		R *= partial_sum;
		for (uint32_t i = 0; i < the_candidates.size(); i++)
		{
            double cur_partial_sum = the_candidates[i].get_partial_sum();
			if (R < cur_partial_sum)
			{
				result_index = i;
				sucess = true;
				break;
			}
		}
	}

    Cell result = the_candidates[result_index];

	// Remove the selected cell from the candidate list
	the_candidates.erase(the_candidates.begin()+result_index);

	// Return the selected cell
	return result;
}

void DBM::run ()
{
    uint32_t max_iter = this->max_iter;
    Grid *the_grid = this->the_grid;
    double h = the_grid->get_discretization();

    for (uint32_t k = 0; k < max_iter; k++)
	{
		// Select a candidate cell
		Cell selected_cell = select_candidate();

		// Place this cell in the grid. Put the cell in the pattern list.
        uint32_t *pos = selected_cell.get_position();
        the_grid->fill_position(pos[0],pos[1],pos[2],FILLED);
		the_pattern.push_back(selected_cell);
		
		// Update the candidates potential with the new cell
		for (uint32_t i = 0; i < the_candidates.size(); i++)
			the_candidates[i].update_potential(selected_cell,h);
		
		// Update neighbours in the grid. Place them in the candidate list
		update_neighbours(selected_cell);

		//printf("Iteration %u\n",k);
		write_to_vtk(k);
		//print(grid);
		//print_list(the_pattern);

	}
}

void DBM::update_candidate (const uint32_t i, const uint32_t j, const uint32_t k)
{
    uint32_t pos[3];
    pos[0] = i;
    pos[1] = j;
    pos[2] = k;

    Grid *the_grid = this->the_grid;
    uint32_t n = the_grid->get_size();
    double h = the_grid->get_discretization();
    the_grid->update_position(pos[0],pos[1],pos[2]);

    if (the_grid->search_position(pos[0],pos[1],pos[2],EMPTY)) 
	{
        the_grid->fill_position(pos[0],pos[1],pos[2],CANDIDATE);
		Cell cell(pos[0],pos[1],pos[2],n,h);
		cell.compute_potential(the_pattern,h);
		the_candidates.push_back(cell);
	}
}

void DBM::update_neighbours (Cell cell)
{
    uint32_t *pos = cell.get_position();

    // North
	update_candidate(pos[0]-1,pos[1],pos[2]);
	// Northeast
	update_candidate(pos[0]-1,pos[1]+1,pos[2]);
	// East
	update_candidate(pos[0],pos[1]+1,pos[2]);
	// Southeast
	update_candidate(pos[0]+1,pos[1]+1,pos[2]);
	// South
	update_candidate(pos[0]+1,pos[1],pos[2]);
	// Southwest
	update_candidate(pos[0]+1,pos[1]-1,pos[2]);
	// West
	update_candidate(pos[0],pos[1]-1,pos[2]);
	// Northwest
	update_candidate(pos[0]-1,pos[1]-1,pos[2]);
    
    // North
	update_candidate(pos[0]-1,pos[1],pos[2]+1);
	// Northeast
	update_candidate(pos[0]-1,pos[1]+1,pos[2]+1);
	// East
	update_candidate(pos[0],pos[1]+1,pos[2]+1);
	// Southeast
	update_candidate(pos[0]+1,pos[1]+1,pos[2]+1);
	// South
	update_candidate(pos[0]+1,pos[1],pos[2]+1);
	// Southwest
	update_candidate(pos[0]+1,pos[1]-1,pos[2]+1);
	// West
	update_candidate(pos[0],pos[1]-1,pos[2]+1);
	// Northwest
	update_candidate(pos[0]-1,pos[1]-1,pos[2]+1);
    // Front
    update_candidate(pos[0],pos[1],pos[2]+1);

    // North
	update_candidate(pos[0]-1,pos[1],pos[2]-1);
	// Northeast
	update_candidate(pos[0]-1,pos[1]+1,pos[2]-1);
	// East
	update_candidate(pos[0],pos[1]+1,pos[2]-1);
	// Southeast
	update_candidate(pos[0]+1,pos[1]+1,pos[2]-1);
	// South
	update_candidate(pos[0]+1,pos[1],pos[2]-1);
	// Southwest
	update_candidate(pos[0]+1,pos[1]-1,pos[2]-1);
	// West
	update_candidate(pos[0],pos[1]-1,pos[2]-1);
	// Northwest
	update_candidate(pos[0]-1,pos[1]-1,pos[2]-1);
    // Back
    update_candidate(pos[0],pos[1],pos[2]-1);
}

void DBM::print ()
{
    printf("GRID\n");
    print_grid();
    printf("GRID\n");

    printf("CANDIDATES\n");
    for (uint32_t i = 0; i < this->the_candidates.size(); i++)
        this->the_candidates[i].print();
    printf("CANDIDATES\n");

    printf("PATTERN\n");
    for (uint32_t i = 0; i < this->the_pattern.size(); i++)
        this->the_pattern[i].print();
    printf("PATTERN\n");
}

void DBM::print_grid ()
{
    this->the_grid->print();
}

void DBM::write_to_vtk (const uint32_t iter)
{
    std::stringstream ss;
    ss << "outputs/iter_" << iter << ".vtk";
    FILE *file = fopen(ss.str().c_str(),"w+");

    fprintf(file,"# vtk DataFile Version 4.1\n");
    fprintf(file,"DBM 3d\n");
    fprintf(file,"ASCII\n");
    fprintf(file,"DATASET POLYDATA\n");
    fprintf(file,"POINTS %u float\n",this->the_pattern.size());
    for (uint32_t i = 0; i < this->the_pattern.size(); i++)
    {
        double *coord = this->the_pattern[i].get_coordinates();
        fprintf(file,"%g %g %g\n",coord[0],coord[1],coord[2]);
    }
    fprintf(file,"VERTICES %u %u\n",this->the_pattern.size(),this->the_pattern.size()*2);
    for (uint32_t i = 0; i < this->the_pattern.size(); i++)
        fprintf(file,"1 %u\n",i);

    fclose(file);
}
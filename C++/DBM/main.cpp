#include <iostream>
#include <cstring>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkCell.h>
#include <vtkLine.h>
#include <vtkVertex.h>
#include <vtkFloatArray.h>
#include <vtkCellData.h>
#include <vtkPointData.h>
#include <vtkPolyDataWriter.h>
#include <vtkXMLPolyDataWriter.h>

#define N 200
#define MAX_ITER 2000
#define H 2
#define ETA 11.0
#define EMPTY ' '
#define CANDIDATE 'C'
#define FILLED 'F'

double euclidean_norm (double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

class Cell
{
public:
	const double R1 = H/2;
	int id;
	int pos[2];			// Position
	double value;		// Eletrostatic potential
	double phi_eta;
	double p;
	double partial_sum;
public:
	Cell (int i, int j)
	{
		this->id = i*N+j;
		this->pos[0] = i;
		this->pos[1] = j;
		this->value = 0;
	}
	void compute_potential (std::vector<Cell*> the_pattern)
	{
		this->value = 0.0;
		
		double x1 = this->pos[0]*H;
		double y1 = this->pos[1]*H;
		for (uint32_t i = 0; i < the_pattern.size(); i++)
		{
			double x2 = the_pattern[i]->pos[0]*H;
			double y2 = the_pattern[i]->pos[1]*H;
			double r_ij = euclidean_norm(x1,y1,x2,y2);

			this->value += (1.0 - (R1/r_ij));	
		}
	}
	void update_potential (Cell *new_cell)
	{
		double x1 = this->pos[0]*H;
		double y1 = this->pos[1]*H;
		double x2 = new_cell->pos[0]*H;
		double y2 = new_cell->pos[1]*H;
		double r_it = euclidean_norm(x1,y1,x2,y2);

		this->value += (1.0 - (R1/r_it));
	}
	void compute_phi_eta (double min_value, double max_value)
	{
		this->phi_eta = pow( (this->value-min_value)/(max_value-min_value),ETA );
	}
	void compute_p (double sum_phi_eta)
	{
		this->p = this->phi_eta / sum_phi_eta;
	}
	void print ()
	{
		printf("%d -> (%d,%d) = %g\n",this->id,this->pos[0],this->pos[1],this->value);
	}
};

void write_to_vtk (char *grid, int iter)
{
	vtkSmartPointer<vtkPolyData> output_polydata = vtkSmartPointer<vtkPolyData>::New();   
    
    uint32_t np = 0;
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (uint32_t i = 0; i < N; i++)
    {
		for (uint32_t j = 0; j < N; j++)
		{
			if (grid[i*N+j] == FILLED)
			{
				double x = i*H;
				double y = j*H;
				points->InsertNextPoint(x,y,0);
				np++;
			}
		}
    }

    vtkSmartPointer<vtkCellArray> vertexes = vtkSmartPointer<vtkCellArray>::New();
    for (uint32_t i = 0; i < np; i++)
    {
        vtkSmartPointer<vtkVertex> vertex  = vtkSmartPointer<vtkVertex>::New();
        vertex->GetPointIds()->SetId(0,i);

        vertexes->InsertNextCell(vertex);
    }

    output_polydata->SetPoints(points);
    output_polydata->SetVerts(vertexes);

	char filename[200];
	sprintf(filename,"outputs/iter_%d.vtk",iter);
	vtkSmartPointer<vtkPolyDataWriter> writer = vtkSmartPointer<vtkPolyDataWriter>::New();
    writer->SetFileName(filename);
    writer->SetInputData(output_polydata);
    writer->Write();
}

void print (char *grid)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%c ",grid[i*N+j]);
		printf("\n");
	}
}

void print_list (std::vector<Cell*> l)
{
	for (uint32_t i = 0; i < l.size(); i++)
		l[i]->print();
}

void set_seed (char *grid, std::vector<Cell*> &the_pattern)
{
	int i = (N/2-1);
	int j = (N/2-1);
	
	Cell *c = new Cell(i,j);
	the_pattern.push_back(c);
	grid[i*N+j] = FILLED;
}

void sort_position (int pos[])
{
	pos[0] = rand() % N;
	pos[1] = rand() % N;
}

void set_position (int i, int j, int pos[])
{
	if (i < 0)
	{
		pos[0] = N-1;
		pos[1] = j;
	}
	else if (i > N-1)
	{
		pos[0] = 0;
		pos[1] = j;
	}
	else if (j < 0)
	{
		pos[0] = i;
		pos[1] = N-1;
	}
	else if (j > N-1)
	{
		pos[0] = i;
		pos[1] = N-1;
	}
	else
	{
		pos[0] = i;
		pos[1] = j;
	}
}

void set_potential (std::vector<Cell*> the_pattern, std::vector<Cell*> &the_candidates)
{
	for (uint32_t i = 0; i < the_candidates.size(); i++)
		the_candidates[i]->compute_potential(the_pattern);
}

void draw_domain ()
{
	double l = N*2;
    double l2 = N;
    
    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0,l,0);
    points->InsertNextPoint(l,l,0);
    points->InsertNextPoint(l,0,0);
    points->InsertNextPoint(0,0,0);
    polydata->SetPoints(points);

    vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
    vtkSmartPointer<vtkLine> line1 = vtkSmartPointer<vtkLine>::New();
    line1->GetPointIds()->SetId(0,0);
    line1->GetPointIds()->SetId(1,1);
    vtkSmartPointer<vtkLine> line2 = vtkSmartPointer<vtkLine>::New();
    line2->GetPointIds()->SetId(0,1);
    line2->GetPointIds()->SetId(1,2);
    vtkSmartPointer<vtkLine> line3 = vtkSmartPointer<vtkLine>::New();
    line3->GetPointIds()->SetId(0,2);
    line3->GetPointIds()->SetId(1,3);
    vtkSmartPointer<vtkLine> line4 = vtkSmartPointer<vtkLine>::New();
    line4->GetPointIds()->SetId(0,3);
    line4->GetPointIds()->SetId(1,0);
    lines->InsertNextCell(line1);
    lines->InsertNextCell(line2);
    lines->InsertNextCell(line3);
    lines->InsertNextCell(line4);
    polydata->SetLines(lines);

    vtkSmartPointer<vtkXMLPolyDataWriter> writer = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
    writer->SetFileName("outputs/domain.vtp");
    writer->SetInputData(polydata);
    writer->Write();
}

void set_candidate (int i, int j, char *grid, std::vector<Cell*> &the_candidates)
{
	int pos[2];
	set_position(i,j,pos);
	grid[pos[0]*N+pos[1]] = CANDIDATE;
	Cell *cell = new Cell(pos[0],pos[1]);
	the_candidates.push_back(cell);
}

void set_neighbours (char *grid, std::vector<Cell*> the_pattern, std::vector<Cell*> &the_candidates)
{
	int north_pos[2], northeast_pos[2], northwest_pos[2];
	int east_pos[2], west_pos[2];
	int south_pos[2], southeast_pos[2], southwest_pos[2];

	for (uint32_t i = 0; i < the_pattern.size(); i++)
	{
		// North
		set_candidate(the_pattern[i]->pos[0]-1,the_pattern[i]->pos[1],grid,the_candidates);
		// Northeast
		set_candidate(the_pattern[i]->pos[0]-1,the_pattern[i]->pos[1]+1,grid,the_candidates);
		// East
		set_candidate(the_pattern[i]->pos[0],the_pattern[i]->pos[1]+1,grid,the_candidates);
		// Southeast
		set_candidate(the_pattern[i]->pos[0]+1,the_pattern[i]->pos[1]+1,grid,the_candidates);
		// South
		set_candidate(the_pattern[i]->pos[0]+1,the_pattern[i]->pos[1],grid,the_candidates);
		// Southwest
		set_candidate(the_pattern[i]->pos[0]+1,the_pattern[i]->pos[1]-1,grid,the_candidates);
		// West
		set_candidate(the_pattern[i]->pos[0],the_pattern[i]->pos[1]-1,grid,the_candidates);
		// Northwest
		set_candidate(the_pattern[i]->pos[0]-1,the_pattern[i]->pos[1]-1,grid,the_candidates);
	}
	
	set_potential(the_pattern,the_candidates);
}

void update_candidate (int i, int j, char *grid, std::vector<Cell*> the_pattern, std::vector<Cell*> &the_candidates)
{
	int pos[2];
	set_position(i,j,pos);
	if (grid[pos[0]*N+pos[1]] == EMPTY) 
	{
		grid[pos[0]*N+pos[1]] = CANDIDATE;
		Cell *cell = new Cell(pos[0],pos[1]);
		cell->compute_potential(the_pattern);
		the_candidates.push_back(cell);
	}
}

void update_neighbours (char *grid, std::vector<Cell*> the_pattern, std::vector<Cell*> &the_candidates, Cell *cell)
{
	int north_pos[2], northeast_pos[2], northwest_pos[2];
	int east_pos[2], west_pos[2];
	int south_pos[2], southeast_pos[2], southwest_pos[2];

	// North
	update_candidate(cell->pos[0]-1,cell->pos[1],grid,the_pattern,the_candidates);
	// Northeast
	update_candidate(cell->pos[0]-1,cell->pos[1]+1,grid,the_pattern,the_candidates);
	// East
	update_candidate(cell->pos[0],cell->pos[1]+1,grid,the_pattern,the_candidates);
	// Southeast
	update_candidate(cell->pos[0]+1,cell->pos[1]+1,grid,the_pattern,the_candidates);
	// South
	update_candidate(cell->pos[0]+1,cell->pos[1],grid,the_pattern,the_candidates);
	// Southwest
	update_candidate(cell->pos[0]+1,cell->pos[1]-1,grid,the_pattern,the_candidates);
	// West
	update_candidate(cell->pos[0],cell->pos[1]-1,grid,the_pattern,the_candidates);
	// Northwest
	update_candidate(cell->pos[0]-1,cell->pos[1]-1,grid,the_pattern,the_candidates);
}

Cell* select_candidate (std::vector<Cell*> &the_candidates)
{
	Cell *result = NULL;
	uint32_t result_index = 0;

	// Business rule to select a cell
	// 1) Get the min/max potential from the candidate list
	double min_value = __DBL_MAX__, max_value = __DBL_MIN__;
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
		if (the_candidates[i]->value < min_value) min_value = the_candidates[i]->value;
		if (the_candidates[i]->value > max_value) max_value = the_candidates[i]->value;
	}
	// 2) Calculate phi_i_eta for each candidate cell
	double sum_phi_eta = 0.0;
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
		the_candidates[i]->compute_phi_eta(min_value,max_value);
		sum_phi_eta += the_candidates[i]->phi_eta;
	}
	// 3) Calculate p_i for each candidate cell
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
		the_candidates[i]->compute_p(sum_phi_eta);
	}
	// 4) Compute the partial sum from the p_i values
	double partial_sum = 0.0;
	for (uint32_t i = 0; i < the_candidates.size(); i++)
	{
		partial_sum += the_candidates[i]->p;
		the_candidates[i]->partial_sum = partial_sum;
	}
	// 5) Get a random number in the interval: [0, partial_sum] --> partial_sum = 1 at the end
	bool sucess = false;
	while (!sucess)
	{
		double R = (double)rand() / (double)RAND_MAX;
		R *= partial_sum;
		for (uint32_t i = 0; i < the_candidates.size(); i++)
		{
			if (R < the_candidates[i]->partial_sum)
			{
				result = the_candidates[i];
				result_index = i;
				sucess = true;
				break;
			}
		}
	}

	// Remove the selected cell from the candidate list
	the_candidates.erase(the_candidates.begin()+result_index);

	// Return the selected cell
	return result;
}

void run_dbm (char *grid, std::vector<Cell*> &the_pattern, std::vector<Cell*> &the_candidates)
{
	for (uint32_t k = 0; k < MAX_ITER; k++)
	{
		// Select a candidate cell
		Cell *selected_cell = select_candidate(the_candidates);
		
		// Place this cell in the grid. Put the cell in the pattern list.
		grid[selected_cell->pos[0]*N+selected_cell->pos[1]] = FILLED;
		the_pattern.push_back(selected_cell);
		
		// Update the candidates potential with the new cell
		for (uint32_t i = 0; i < the_candidates.size(); i++)
			the_candidates[i]->update_potential(selected_cell);
		
		// Update neighbours in the grid. Place them in the candidate list
		update_neighbours(grid,the_pattern,the_candidates,selected_cell);

		//printf("Iteration %u\n",k);
		write_to_vtk(grid,k);
		//print(grid);
		//print_list(the_pattern);

	}
}

int main (int argc, char *argv[])
{
	std::vector<Cell*> the_pattern;
	std::vector<Cell*> the_candidates;

	char *grid = new char[N*N]();
	memset(grid,EMPTY,sizeof(char)*N*N);

	set_seed(grid,the_pattern);
	set_neighbours(grid,the_pattern,the_candidates);
	
	run_dbm(grid,the_pattern,the_candidates);

	delete [] grid;
	return 0;
}

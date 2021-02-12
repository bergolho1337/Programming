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

#define N 500
#define MAX_ITER 2000
#define CX 2
#define CY 2
#define STIFF_FACTOR 1
#define FILL '+'
#define NO_FILL ' '

void write_to_vtk (char *grid, int iter)
{
	vtkSmartPointer<vtkPolyData> output_polydata = vtkSmartPointer<vtkPolyData>::New();   
    
    uint32_t np = 0;
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (uint32_t i = 0; i < N; i++)
    {
		for (uint32_t j = 0; j < N; j++)
		{
			if (grid[i*N+j] == FILL)
			{
				double x = i*CX;
				double y = j*CY;
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

void set_seed (char *grid, int *grid_counter)
{
	grid[(N/2-1)*N+(N/2-1)] = FILL;
	grid_counter[(N/2-1)*N+(N/2-1)]++;
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

bool check_neighbours (char *grid, int pos[])
{
	int north_pos[2], northeast_pos[2], northwest_pos[2];
	int east_pos[2], west_pos[2];
	int south_pos[2], southeast_pos[2], southwest_pos[2];

	set_position(pos[0]-1,pos[1],north_pos);
	set_position(pos[0]-1,pos[1]+1,northeast_pos);
	set_position(pos[0],pos[1]+1,east_pos);
	set_position(pos[0]+1,pos[1]+1,southeast_pos);
	set_position(pos[0]+1,pos[1],south_pos);
	set_position(pos[0]+1,pos[1]-1,southwest_pos);
	set_position(pos[0],pos[1]-1,west_pos);
	set_position(pos[0]-1,pos[1]-1,northwest_pos);
	
	if ( (grid[ north_pos[0]*N+north_pos[1] ] == FILL) || (grid[ northeast_pos[0]*N+northeast_pos[1] ] == FILL) || (grid[ northwest_pos[0]*N+northwest_pos[1] ] == FILL) ||\
	     (grid[ east_pos[0]*N+east_pos[1] ] == FILL) || (grid[ west_pos[0]*N+west_pos[1] ] == FILL) ||\
		 (grid[ south_pos[0]*N+south_pos[1] ] == FILL) || (grid[ southeast_pos[0]*N+southeast_pos[1] ] == FILL) || (grid[ southwest_pos[0]*N+southwest_pos[1] ] == FILL) )
		return true;
	else
		return false;
}

void random_walk (char *grid, int *grid_counter, int pos[])
{
	int i = pos[0];
	int j = pos[1];
	int counter = 0;
	while (!check_neighbours(grid,pos))
	{
		int dir = rand() % 8;
		// Start position
		i = pos[0]; j = pos[1];
		switch (dir)
		{
			// North
			case 0:
				set_position(i-1,j,pos);
				break;
			// Northeast
			case 1:
				set_position(i-1,j+1,pos);
				break;
			// East
			case 2:
				set_position(i,j+1,pos);
				break;
			// Southeast
			case 3:
				set_position(i+1,j+1,pos);
				break;
			// South
			case 4:
				set_position(i+1,j,pos);
				break;
			// Southwest
			case 5:
				set_position(i+1,j-1,pos);
				break;
			// West
			case 6:
				set_position(i,j-1,pos);
				break;
			// Northwest
			case 7:
				set_position(i-1,j-1,pos);
				break;
			default:
				break;
		}
		counter++;
		// pos[] = Stores the new position
	}
	// Check stiffness
	double p = (double)rand() / (double)RAND_MAX;
	if (p < STIFF_FACTOR)
	{
		grid[i*N+j] = FILL;
		//grid_counter[pos[0]*N+pos[1]]++;
	}
		
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

int main (int argc, char *argv[])
{
	char *grid = new char[N*N]();
	int *grid_counter = new int[N*N]();
	memset(grid,NO_FILL,sizeof(char)*N*N);
	memset(grid_counter,0,sizeof(int)*N*N);

	set_seed(grid,grid_counter);
	write_to_vtk(grid,0);
	draw_domain();

	int pos[2];
	for (int k = 1; k < MAX_ITER; k++)
	{
		sort_position(pos);
		random_walk(grid,grid_counter,pos);
		write_to_vtk(grid,k);	
	}

	delete [] grid;
	delete [] grid_counter;
	return 0;
}

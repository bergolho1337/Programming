#include "grid.h"

Grid::Grid (const uint32_t n, const double h)
{
    this->n = n;
    this->h = h;
    this->grid = new char[n*n*n]();
    memset(grid,EMPTY,sizeof(char)*n*n*n);
}

Grid::~Grid ()
{
    if (this->grid)
        delete [] this->grid;
}

void Grid::fill_position (const uint32_t i, const uint32_t j, const uint32_t k, const char value)
{
    uint32_t id = get_id(i,j,k);
    this->grid[id] = value;
}

bool Grid::update_position (uint32_t &i, uint32_t &j, uint32_t &k)
{
    uint32_t n = this->n;

    if (i < 0)
		i = 0;
	else if (i > n-1)
		i = n-1;
    if (j < 0)
		j = 0;
	else if (j > n-1)
		j = n-1;
    if (k < 0)
		k = 0;
	else if (k > n-1)
		k = n-1;
    return true;
}

bool Grid::search_position (const uint32_t i, const uint32_t j, const uint32_t k, const char value)
{
    uint32_t id = get_id(i,j,k);
    return (this->grid[id] == value) ? true : false;
}

uint32_t Grid::get_id (const uint32_t i, const uint32_t j, const uint32_t k)
{
    return (k*this->n*this->n)+(i*this->n+j);
}

uint32_t Grid::count_number_cells (std::vector<uint32_t> &ids, const char key)
{
    for (uint32_t k = 0; k < n; k++)
    {
        for (uint32_t i = 0; i < n; i++)
        {
            for (uint32_t j = 0; j < n; j++)
            {
                uint32_t id = get_id(i,j,k);
                if (grid[id] == key)
                    ids.push_back(id);
            }
        }
    }
    return ids.size();
}

void Grid::print ()
{
    uint32_t n = this->n;
    for (uint32_t k = 0; k < n; k++)
    {
        for (uint32_t i = 0; i < n; i++)
        {
            for (uint32_t j = 0; j < n; j++)
            {
                uint32_t id = get_id(i,j,k);
                printf("%c ",this->grid[id]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}

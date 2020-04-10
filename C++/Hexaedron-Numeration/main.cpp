#include <iostream>
#include <cmath>
#include <cstdint>

#define SIDE_LENGTH_X 15
#define SIDE_LENGTH_Y 15
#define DX 5
#define DY 5
#define DZ 5

int main ()
{
	uint32_t counter = 0;
	uint32_t nx = nearbyint(SIDE_LENGTH_X/DX);
	uint32_t ny = nearbyint(SIDE_LENGTH_Y/DY);

	for (uint32_t k = 0; k < 2; k++)
	{
		double z = k*DZ;
		for (uint32_t i = 0; i <= ny; i++)
		{
			double y = i*DY;
			for (uint32_t j = 0; j <= nx; j++)
			{
				double x = j*DX;

				printf("Point %u = (%g,%g,%g)\n",counter,x,y,z);

				counter++;
			}
		}	
	}

	printf("--------------------------------------------------------\n");

	counter = 0;
	for (uint32_t i = 0; i < ny; i++)
	{
		for (uint32_t j = 0; j < nx; j++)
		{
			uint32_t k = i*(ny+1) + j;

			printf("Cell %u = [%u %u %u %u %u %u %u %u]\n",counter,\
															k, k+1,\
															k+(nx+1), k+(nx+1)+1,\
															k+((nx+1)*(ny+1)),k+((nx+1)*(ny+1))+1,\
															k+((nx+1)*(ny+1))+(nx+1),k+((nx+1)*(ny+1))+(nx+1)+1);

			counter++;
		}
	}
	

	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>

using namespace std;

uint32_t count_number_of_lines (const char filename[])
{
	FILE *file = fopen(filename,"r");

        double values[2];
        uint32_t counter = 0;
        while (fscanf(file,"%lf %lf",&values[0],&values[1]) != EOF)
                counter++;

        fclose(file);

	return counter;
}

double* read_data_file (const char filename[], const uint32_t num_lines)
{
	double *ret = new double[num_lines]();

	FILE *file = fopen(filename,"r");

	double values[2];
	for (uint32_t i = 0; i < num_lines; i++)
	{
		fscanf(file,"%lf %lf",&values[0],&values[1]);

		ret[i] = values[1];
	}

	fclose(file);

	return ret;
}

double calculate_rms (const double y_true[], const double y_pred[], const uint32_t n)
{
	double sum = 0.0;
	for (uint32_t i = 0; i < n; i++)
	{
		double value = (y_true[i] - y_pred[i]) / (y_true[i]); 
		sum += powf(value,2);
	}
	sum /= (double)n;

	return sqrt(sum);
}

int main (int argc, char *argv[])
{
	if (argc-1 != 2)
	{
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        	printf("Usage:> %s <reference_filename> <aproximation_filename>\n",argv[0]);
        	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		exit(EXIT_FAILURE);
	}

	uint32_t num_lines = count_number_of_lines(argv[1]);

	double *ref_data = read_data_file(argv[1],num_lines);
	double *aprox_data = read_data_file(argv[2],num_lines);

	printf("RMS = %.10lf\n",calculate_rms(ref_data,aprox_data,num_lines));

	delete [] ref_data;
	delete [] aprox_data;

	return 0;
}

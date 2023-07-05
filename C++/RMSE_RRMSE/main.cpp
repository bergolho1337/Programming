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

double calculate_rmse (const double y_true[], const double y_pred[], const uint32_t n)
{
	double sum = 0.0;
	for (uint32_t i = 0; i < n; i++)
	{
		double value = pow(y_true[i] - y_pred[i], 2); 
		sum += value;
	}
	sum /= (double)n;

	return sqrt(sum);
}

double calculate_rrmse_v1 (const double y_true[], const double y_pred[], const uint32_t n)
{
	double num = 0.0, den = 0.0;
	for (uint32_t i = 0; i < n; i++)
	{
		num += pow(y_true[i] - y_pred[i], 2); 
		den += fabs(y_true[i]);
	}
	return sqrt(num/den);
}

double calculate_rrmse_v2 (const double y_true[], const double y_pred[], const uint32_t n)
{
	double num = 0.0, den = 0.0;
	for (uint32_t i = 0; i < n; i++)
	{
		num += pow(y_true[i] - y_pred[i], 2); 
		den += pow(y_pred[i], 2);
	}
	//num /= (double)n;
	return sqrt(num/den);
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

	printf("RMSE = %.10lf\n",calculate_rmse(ref_data,aprox_data,num_lines));
	printf("RRMSE v1 = %.10lf\n",calculate_rrmse_v1(ref_data,aprox_data,num_lines));
	printf("RRMSE v2 = %.10lf\n",calculate_rrmse_v2(ref_data,aprox_data,num_lines));


	delete [] ref_data;
	delete [] aprox_data;

	return 0;
}

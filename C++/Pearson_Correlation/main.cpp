#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

double mean (std::vector<double> in) {
	uint32_t n = in.size();
	double out = 0.0;
	for (uint32_t i = 0; i < n; i++) {
		out += in[i];
	}
	return out/(double)n;
}

double std_dev (std::vector<double> in) {
	uint32_t n = in.size();
	double m = mean(in);
	double sum = 0.0;
	for (uint32_t i = 0; i < n; i++) {
		sum += pow(in[i]-m,2);
	}
	return sqrt(sum/(double)(n));
}

std::vector<double> pow2_vector (std::vector<double> in) {
	uint32_t n = in.size();
	std::vector<double> out(n,0);
	for (uint32_t i = 0; i < n; i++) {
		out[i] = in[i]*in[i];
	}
	return out;
}

std::vector<double> mult_vector (std::vector<double> in1, std::vector<double> in2) {
	uint32_t n1 = in1.size();
	uint32_t n2 = in2.size();
	assert(n1 == n2);

	std::vector<double> out(n1,0);
	for (uint32_t i = 0; i < n1; i++) {
		out[i] = in1[i]*in2[i];
	}
	return out;
}

double sum_vector (std::vector<double> in) {
	uint32_t n = in.size();
	double out = 0.0;
	for (uint32_t i = 0; i < n; i++) {
		out += in[i];
	}
	return out;
}

void print_vector (std::vector<double> in) {
	uint32_t n = in.size();
	for (uint32_t i = 0; i < n; i++) {
		printf("%g ",in[i]);
	}
	printf("\n");
}

double pearson (const double sum_x, const double sum_y, const double sum_xy, const double sum_x2, const double sum_y2, const uint32_t n) {
	return ((n*sum_xy) - (sum_x*sum_y)) / sqrt( (n*sum_x2 - (sum_x*sum_x)) * (n*sum_y2 - (sum_y*sum_y)) );
}

int main (int argc, char *argv[])
{
	// Input 1
	//std::vector<double> x = {-2,-1,0,1,2};
	//std::vector<double> y = {4,1,3,2,0};
	// Input 2
	std::vector<double> x = {6,8,10};
	std::vector<double> y = {12,10,20};
	
	std::vector<double> x2 = pow2_vector(x);
	std::vector<double> y2 = pow2_vector(y);
	std::vector<double> xy = mult_vector(x,y);

	double sum_x = sum_vector(x);
	double sum_y = sum_vector(y);
	double sum_xy = sum_vector(xy);
	double sum_x2 = sum_vector(x2);
	double sum_y2 = sum_vector(y2);

	print_vector(x);
	print_vector(y);
	print_vector(x2);
	print_vector(y2);
	print_vector(xy);

	printf("%g\n",sum_x);
	printf("%g\n",sum_y);
	printf("%g\n",sum_xy);
	printf("%g\n",sum_x2);
	printf("%g\n",sum_y2);

	double r = pearson(sum_x,sum_y,sum_xy,sum_x2,sum_y2,x.size());
	printf("Pearson correlation = %g\n",r);

	return 0;
}

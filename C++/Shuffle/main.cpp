#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void print_array (std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main (int argc, char *argv[])
{
	std::vector<int> arr(10);
	std::vector<int> arr_shuffle(10);
	std::iota(arr.begin(),arr.end(),0);
	print_array(arr);

	std::copy(arr.begin(),arr.end(),arr_shuffle.begin());
	std::random_shuffle(arr_shuffle.begin(),arr_shuffle.end());
	print_array(arr_shuffle);

	return 0;
}

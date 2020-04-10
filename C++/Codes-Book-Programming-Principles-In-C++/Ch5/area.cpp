#include <iostream>

using namespace std;

class Bad_area {};

int area (int length, int width)
{
	if (length <= 0 || width <= 0) throw Bad_area{};
	return length*width;
}

int main ()
{
	try
	{
		int x = -1;
		int y = 2;
		int z = 4;
		int area1 = area(x,y);
		cout << "Area = " << area1 << endl;
	}
	catch(Bad_area)
	{
		cout << "Ops! Bad arguments to area()" << endl;
	}
}

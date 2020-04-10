#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main ()
{
	vector<int> myvector(10);
	try
	{
		myvector.at(20) = 100;
	}
	catch(out_of_range &oor)
	{
		cerr << "Out of range error: " << oor.what() << endl;
	}
	return 0;
}

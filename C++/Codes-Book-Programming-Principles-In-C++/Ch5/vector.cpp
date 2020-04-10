#include <iostream>
#include <vector>
//#include <stdexcept>
#include "std_lib_facilities.h"

using namespace std;

int main ()
{
	try
	{
		vector<int> v;
		for (int i; cin >> i;)
			v.push_back(i);
		for (int i = 0; i <= v.size(); ++i)
			cout << "v[" << i << "] == " << v[i] << endl;
	}
	catch(out_of_range)
	{
		cerr << "Oops! Range error!" << endl;
		return 1;
	}
	catch(...) // Catch all other exceptions
	{
		cerr << "Exception: something went wrong!" << endl;
		return 2;
	}
}

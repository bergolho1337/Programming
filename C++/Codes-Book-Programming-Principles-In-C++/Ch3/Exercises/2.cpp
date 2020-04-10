#include <iostream>

using namespace std;

int main ()
{
	double miles;
	cout << "Enter the miles to be converted:";
	cin >> miles;
	cout << miles << " miles = " << miles*1.609 << " kilometers" << endl;
	return 0; 
}

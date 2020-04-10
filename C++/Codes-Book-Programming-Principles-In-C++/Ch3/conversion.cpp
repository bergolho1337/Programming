// Compile:
// g++ -std=c++11 conversion.cpp -o conversion

#include <iostream>

using namespace std;

int main ()
{
	double d = 0;
	while (cin >> d)
	{
		int i = d;
		char c = i;
		int i2 = c;
		cout << "d = " << d << endl; 
		cout << "i = " << i << endl;
		cout << "i2 = " << i2 << endl;
		cout << "char (" << c << ")" << endl;
	}
	// Use the universal and uniform initialization to avoid the errors caused by narrowing variables.
	double x {2.7};
	int y {x};				// This will throw a exception, because a 'double' doesn't fit on a 'int'.
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	return 0;
} 

// [!] The conversion double to int is equivalent to the floor() operation in the <cmath> library.
// [!] Word = 4 byte = 32 bits

// Size of each type:
// int    -> 4 bytes = 32 bits
// char   -> 1 byte = 8 bits
// bool   -> 1 byte = 8 bits
// double -> 8 bytes = 64 bits

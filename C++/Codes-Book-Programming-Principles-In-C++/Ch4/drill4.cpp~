#include <iostream>

using namespace std;

int main ()
{
	char c;
	int a, b;
	cout << "Reading input. Enter a and b." << endl;
	while (cin >> a >> b)
	{
		if (a > b)
		{
			cout << "The smaller value is: " << b << endl;
			cout << "The larger value is: " << a << endl;
		}
		else if (a < b)
		{
			cout << "The smaller value is: " << a << endl;
			cout << "The larger value is: " << b << endl;
		}
		else
		{
			cout << "The numbers are equal." << endl;
		}
		cout << "Proceed reading ? Type '|' to quit.";
		cin >> c;
		if (c == '|')
			break;
		cout << "Reading input. Enter a and b." << endl;
	}
	return 0;
}

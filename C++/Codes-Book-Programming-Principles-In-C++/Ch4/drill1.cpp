#include <iostream>

using namespace std;

int main ()
{
	char c;
	int a, b;
	cout << "Reading input" << endl;
	while (cin >> a >> b)
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "Proceed reading ? Type '|' to quit.";
		cin >> c;
		if (c == '|')
			break;
	}
	return 0;
}

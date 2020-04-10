#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	char c;
	double a;
  double max, min;
  max = -1.0e+100;
  min = 1.0e+100;
	cout << "Reading input. Enter a." << endl;
	while (cin >> a)
	{
    cout << "Read number " << a << endl;
		if (a > max)
    {
      cout << "\tThe largest so far" << endl;
      max = a;
    }
    if (a < min)
    {
      cout << "\tThe smallest so far" << endl;
      min = a;
    }
    cout << "Proceed reading ? Type '|' to quit.";
		cin >> c;
		if (c == '|')
			break;
		cout << "Reading input. Enter a." << endl;
	}
	return 0;
}

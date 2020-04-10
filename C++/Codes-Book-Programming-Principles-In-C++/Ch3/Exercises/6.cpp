#include <iostream>

using namespace std;

int main()
{
	int a, b, c, aux;
	cout << "Enter three numbers: ";
	cin >> a >> b >> c;
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	if (b > c)
	{
		aux = b;
		b = c;
		c = aux;
	}
	cout << a << ", " << b << ", " << c << endl;
}

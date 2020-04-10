#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b, c, aux;
	cout << "Enter three strings: ";
	cin >> a >> b >> c;
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	if (a > c)
	{
		aux = a;
		a = c;
		c = aux;
	}
	if (b > c)
	{
		aux = b;
		b = c;
		c = aux;
	}
	cout << a << ", " << b << ", " << c << endl;
}

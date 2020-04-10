// Exercise 5 and 6

#include <iostream>

using namespace std;

// Converts from Celsius to Kelvin
double ctok (double c)
{
  if (c < -273.15)
  {
    cerr << "[-] Error! Temperature below absolute zero!" << endl;
    return -1;
  }
  else
  {
    double k = c + 273.15;
    return k;
  }
}

// Converts from Kelvin to Celsius
double ktoc (double k)
{
  if (k < 0)
  {
    cerr << "[-] ERROR! Temperature below absolute zero!" << endl;
    return -1;
  }
  else
  {
    double c = k - 273.15;
    return c;
  }
}

// Converts from Celsius to Farenheit
double ctof (double c)
{
  if (c < -273.15)
  {
    cerr << "[-] Error! Temperature below absolute zero!" << endl;
    return -1;
  }
  else
  {
    double f = 9.0*c/5.0 + 32.0;
    return f;
  }
}

// Converts from Farenheit to Celsius
double ftoc (double f)
{
  if (f < -459.653)
  {
    cerr << "[-] Error! Temperature below absolute zero!" << endl;
    return -1;
  }
  else
  {
    double c = (f-32.0)*5.0/9.0;
    return c;
  }
}

int main ()
{
  double c, k, f;
  cout << "Temperature in Celsius: ";
  cin >> c;
  k = ctok(c);
  f = ctof(c);
  cout << c << " Celsius = " << k << " Kelvin" << endl;
  cout << c << " Celsius = " << f << " Farenheit" << endl;

  cout << "Temperature in Kelvin: ";
  cin >> k;
  c = ktoc(k);
  f = ctof(c);
  cout << k << " Kelvin = " << c << " Celsius" << endl;
  cout << k << " Kelvin = " << f << " Farenheit" << endl;

  cout << "Temperature in Farenheit: ";
  cin >> f;
  c = ftoc(f);
  k = ctok(c);
  cout << f << " Farenheit = " << c << " Celsius" << endl;
  cout << f << " Farenheit = " << k << " Kelvin" << endl;

  return 0;
}

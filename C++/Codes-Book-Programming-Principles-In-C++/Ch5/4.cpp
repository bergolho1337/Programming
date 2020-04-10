#include <iostream>

using namespace std;

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

int main ()
{
  double c = 0;
  cin >> c;
  double k = ctok(c);
  cout << k << endl;
}

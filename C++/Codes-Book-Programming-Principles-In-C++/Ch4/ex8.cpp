#include <iostream>
#include <cmath>

using namespace std;

int howMany (int g)
{
  int sum, square;
  sum = 1;
  square = 1;
  while (sum <= g)
  {
    cout << "Square = " << square << "\t" << "Grains = " << sum << endl;
    sum += pow(2,square);
    square++;
  }
  cout << "Square = " << square << "\t" << "Grains = " << sum << endl;
  return (square);
}

int main ()
{
  cout << "For 1000 grains of rice " << howMany(1000) << " grains of rice are required." << endl << endl;
  cout << "For 100000 grains of rice " << howMany(100000) << " grains of rice are required." << endl << endl;
  cout << "For 1000000000 grains of rice " << howMany(1000000000) << " grains of rice are required." << endl << endl;
}

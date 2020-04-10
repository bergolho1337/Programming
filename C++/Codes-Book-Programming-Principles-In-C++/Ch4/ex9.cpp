#include <iostream>
#include <cmath>

using namespace std;

void howMany ()
{
  int sum;
  double sumD;
  sum = 1;
  sumD = 1.0;
  for (int i = 1; i <= 64; i++)
  {
    cout << "Square = " << i << "\tGrains(int) = " << sum << "\t\tGrains(double) = " << sumD << endl;
    sum += pow(2,i);
    sumD += pow(2,i);
  }
}

int main ()
{
    howMany();
    return 0;
}

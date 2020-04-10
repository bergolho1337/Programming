#include <iostream>
#include <cmath>

using namespace std;

void readInput (double *a, double *b, double *c)
{
  cout << "Write the coeffients a, b, c: ";
  cin >> *a >> *b >> *c;
}

void solveEquation (double a, double b, double c, double *x1, double *x2)
{
  *x1 = (-b + sqrt(b*b-4*a*c)) / 2*a;
  *x2 = (-b - sqrt(b*b-4*a*c)) / 2*a;
}

int main ()
{
  double a, b, c;
  double x1, x2;
  readInput(&a,&b,&c);
  solveEquation(a,b,c,&x1,&x2);
  cout << "The solution to: " << a << "x^2 + " << b << "x + " << c << endl;
  cout << "x1 = " << x1 << endl;
  cout << "x2 = " << x2 << endl;
  return 0;
}

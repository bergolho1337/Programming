#include <iostream>
#include <cmath>

using namespace std;

double* solveEquation_2 (double a, double b, double c)
{
  double *x;
  double delta;
  double check1, check2;
  delta = pow(b,2) - 4*a*c;
  if (delta < 0)
  {
    cerr << "[!] ERROR! No real roots, delta value is negative!" << endl;
    return NULL;
  }
  else
  {
    x = new double[2];
    x[0] = (-b + sqrt(delta)) / (2.0*a);
    x[1] = (-b - sqrt(delta)) / (2.0*a);

    cout << "Solution" << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;

    check1 = a*pow(x[0],2) + b*x[0] + c;
    check2 = a*pow(x[1],2) + b*x[1] + c;
    cout << "Checking solution" << endl;
    cout << "ax^2 + bx + c = 0" << endl;
    cout << "x1 --> (" << a << " * " << x[0] << "^2) + (" << b << " * " << x[0] << ") + (" << c << ")" << endl;
    cout << check1 << " = 0" << endl;
    cout << "x2 --> (" << a << " * " << x[1] << "^2) + (" << b << " * " << x[1] << ") + (" << c << ")" << endl;
    cout << check2 << " = 0" << endl;

    return x;
  }
}

int main ()
{
  double a, b, c;
  double *x;

  cout << "Coeficientes a,b,c: ";
  cin >> a >> b >> c;

  x = solveEquation_2(a,b,c);

  if (x != NULL)
    delete [] x;

  return 0;
}

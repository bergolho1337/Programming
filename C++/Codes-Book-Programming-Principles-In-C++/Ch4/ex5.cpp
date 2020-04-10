#include <iostream>

using namespace std;

void makeOperation (double a, double b, char op)
{
  switch (op)
  {
    case '+': cout << "The sum of " << a << " and " << b << " is " << a+b << endl;
              break;
    case '-': cout << "The subtraction of " << a << " and " << b << " is " << a-b << endl;
              break;
    case '*': cout << "The product of " << a << " and " << b << " is " << a*b << endl;
              break;
    case '/': if (b == 0)
                cout << "[-] Error! Division by zero!" << endl;
              else
                cout << "The division of " << a << " and " << b << " is " << a/b << endl;
              break;
    default: cout << "[-] Error! Unknown operation!" << endl;
  }
}

int main ()
{
  double a, b;
  char op;
  cout << "Enter a, b: ";
  cin >> a >> b;
  cout << "Enter operation: ";
  cin >> op;
  makeOperation(a,b,op);
}

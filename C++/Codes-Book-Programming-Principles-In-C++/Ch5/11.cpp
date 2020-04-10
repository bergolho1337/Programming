#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int val, i;
  vector<int> fib;
  fib.push_back(1);
  fib.push_back(1);
  i = 1;
  while (fib[i] > 0)
  {
    i++;
    val = fib[i-2]+fib[i-1];
    fib.push_back(val);
  }
  cout << "The last Fibonacci number that can be place in a int is" << endl;
  cout << "Fib(" << i-1 << ") = " << fib[i-1] << endl;
  cout << "Fib(" << i << ") = " << fib[i] << endl;

  return 0;
}

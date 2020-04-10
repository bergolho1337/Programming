#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

typedef long long int ll;

double sumElements (vector<double> v, int N)
{
  if (N > v.size())
  {
    cerr << "[-] ERROR! Not enough elements in the vector to make the sum (" << N << " > " << v.size() << ")" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    double sum = 0;

    for (int i = 0; i < N; i++)
      sum += v[i];

    cout << "The sum of the first " << N << " numbers (";
    for (int i = 0; i < N; i++)
      cout << v[i] << " ";
    cout << ") is " << sum << endl;
    return sum;
  }
}

vector<double> diffAdjacent (vector<double> v)
{
  vector<double> dif;
  for (int i = 0; i < v.size()-1; i++)
    dif.push_back(fabs(v[i]-v[i+1]));

  cout << "Vector containing the " << dif.size() << " differences between adjacent values" << endl;
  for (int i = 0; i < dif.size(); i++)
    cout << dif[i] << " ";
  cout << endl;

  return dif;
}

int main ()
{
  int N;
  double value;
  double sum;
  vector<double> v, dif;

  cout << "Please enter the number of values you want to sum: ";
  cin >> N;

  cout << "Please enter some integers (press '|' to stop)" << endl;
  try
  {
    while (cin >> value)
    {

      if (value == '|')
        break;

      v.push_back(value);
    }
    sum = sumElements(v,N);
    dif = diffAdjacent(v);
  }
  catch (exception &e)
  {
    cerr << "[-] ERROR! " << e.what() << endl;
    exit(EXIT_FAILURE);
  }

  return 0;

}

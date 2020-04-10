#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int sumElements (vector<int> v, int N)
{
  if (N > v.size())
  {
    cerr << "[-] ERROR! Not enough elements in the vector to make the sum (" << N << " > " << v.size() << ")" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    int sum = 0;
    for (int i = 0; i < N; i++)
      sum += v[i];

    cout << "The sum of the first " << N << " numbers (";
    for (int i = 0; i < N; i++)
      cout << v[i] << " ";
    cout << ") is " << sum << endl;
    return sum;
  }
}

int main ()
{
  int N;
  int value, sum;
  vector<int> v;

  cout << "Please enter the number of values you want to sum: ";
  cin >> N;

  cout << "Please enter some integers (press '|' to stop)" << endl;
  while (cin >> value)
  {
    if (value == '|')
      break;
    v.push_back(value);
  }
  sum = sumElements(v,N);
  return 0;

}

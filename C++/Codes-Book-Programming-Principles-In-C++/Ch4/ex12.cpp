#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int i, j;
  int max;
  vector<int> primes;
  cout << "What is the max value: ";
  cin >> max;
  // Find all the primes between 1 and 100
  primes.push_back(2);
  for (i = 3; i < max; i += 2)
  {
    for (j = 0; j < primes.size(); j++)
    {
      if (i % primes[j] == 0)
        break;
    }
    if (j == primes.size())
      primes.push_back(i);
  }
  // List the primes
  cout << "There are " << primes.size() << endl;
  cout << "[+] Listing primes between [1," << max << "]" << endl;
  for (int i = 0; i < primes.size(); i++)
    cout << primes[i] << endl;
  return 0;
}

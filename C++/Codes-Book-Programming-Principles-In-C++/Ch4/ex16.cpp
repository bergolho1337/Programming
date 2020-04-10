#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  // Read series
  vector<int> v;
  int maxCont, value;
  maxCont = 0;
  cout << "Enter the sequence: ";
  for (int n; cin >> n;)
    v.push_back(n);
  // Cont how many times each term apper
  for (int i = 0; i < v.size(); i++)
  {
    int cont = 0;
    for (int j = 0; j < v.size(); j++)
    {
      if (v[i] == v[j])
        cont++;
    }
    if (cont > maxCont)
    {
      maxCont = cont;
      value = v[i];
    }
  }
  cout << "The number that appears most in the sequence (mode) is: " << value << endl;
  cout << "It appears " << maxCont << " times" << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
  // Read series
  vector<string> v;
  int maxCont;
  string value, maxString, minString;
  maxCont = 0;
  cout << "Enter the sequence: ";
  for (string n; cin >> n;)
    v.push_back(n);
  // Initialize max and min strings with the first element
  maxString = minString = v[0];
  for (int i = 0; i < v.size(); i++)
  {
    int cont = 0;
    // Check for min and max strings
    if (v[i] > maxString)
      maxString = v[i];
    if (v[i] < minString)
      minString = v[i];
    // Cont how many times each term apper
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
  cout << "The string that appears most in the sequence (mode) is: " << value << endl;
  cout << "It appears " << maxCont << " times" << endl;
  cout << "The max string is: " << maxString << endl;
  cout << "The min string is: " << minString << endl;
  return 0;
}

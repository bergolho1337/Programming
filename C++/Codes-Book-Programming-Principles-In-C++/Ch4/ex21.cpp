#include <iostream>
#include <vector>
#include <string>

using namespace std;

void checkUnique (vector<string> names)
{
  cout << "Checking unique names" << endl;
  bool tick = true;
  int i, j;
  for (i = 0; i < names.size(); i++)
  {
    for (j = i+1; j < names.size(); j++)
    {
      if (names[i] == names[j])
      {
        tick = false;
        break;
      }
    }
  }
  if (!tick)
    cout << "[-] Error! There is a name entered twice." << endl;
}

void printPairs (vector<string> names, vector<int> values)
{
  cout << "Printing pairs" << endl;
  for (int i = 0; i < names.size(); i++)
    cout << "(" << names[i] << "," << values[i] << ")" << endl;
}

void searchScore (vector<int> values, vector<string> names, int value)
{
  int i;
  cout << "Printing all names with score " << value << endl;
  for (i = 0; i < values.size(); i++)
  {
    if (values[i] == value)
      cout << names[i] << endl;
  }
}

int main ()
{
  int value, k;
  string name;
  vector<string> names;
  vector<int> values;
  cout << "Enter (name,score): ";
  while (cin >> name >> value)
  {
    if (name == "NoName" && value == 0)
      break;
    names.push_back(name);
    values.push_back(value);
    cout << "Enter (name,score): ";
  }
  //checkUnique(names);
  printPairs(names,values);

  cout << "Enter a score: ";
  cin >> value;
  searchScore(values,names,value);
  return 0;
}

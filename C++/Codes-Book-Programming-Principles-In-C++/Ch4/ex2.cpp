#include <iostream>
#include <vector>

using namespace std;

void printMedian (vector<double> seq)
{
  cout << "[!] Median = ";
  if (seq.size() % 2 == 0)
    cout << (seq[seq.size()/2]+seq[seq.size()/2-1]) / 2.0 << endl;
  else
    cout << seq[seq.size()/2] << endl;
}

void printVector (vector<double> seq)
{
  cout << "[!] Printing sequence of numbers ..." << endl;
  for (int i = 0; i < seq.size(); i++)
    cout << seq[i] << " ";
  cout << endl;
}

int main ()
{
  double number;
  vector<double> seq;
  cout << "[!] Reading numbers ..." << endl;
  while (cin >> number)
    seq.push_back(number);
  printVector(seq);
  printMedian(seq);
  return 0;
}

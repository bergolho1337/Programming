#include <iostream>
#include <vector>

using namespace std;

void printMean (vector<double> seq, double sum)
{
  cout << "[!] Sum of distance = " << sum << endl;
  cout << "[!] Mean = " << sum/(double)seq.size() << endl;
}

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
  double smallest, biggest;
  smallest = biggest = seq[0];
  cout << "[!] Printing sequence ..." << endl;
  for (int i = 0; i < seq.size(); i++)
  {
    cout << seq[i] << " ";
    if (seq[i] < smallest)
      smallest = seq[i];
    if (seq[i] > biggest)
      biggest = seq[i];
  }
  cout << endl;
  cout << "[+] Greatest distance = " << biggest << endl;
  cout << "[+] Smallest distance = " << smallest << endl;
}

int main ()
{
  double dist, sum;
  vector<double> seq;
  sum = 0.0;
  cout << "[!] Reading distances ..." << endl;
  while (cin >> dist)
  {
    sum += dist;
    seq.push_back(dist);
  }
  printVector(seq);
  printMean(seq,sum);
  //printMedian(seq);
  return 0;
}

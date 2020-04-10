#include <iostream>

using namespace std;

int readNumber ()
{
  int number;
  cout << "[!] Think of a number between 1 and 100: ";
  cin >> number;
  return (number);
}

void tryGuess (int minV, int maxV)
{
  char c;
  if (maxV-minV == 1)
    cout << "The number you are guessing is " << (maxV+minV)/2  << endl;
  else
  {
    cout << "Is the number you are thinking of less than " << (maxV+minV)/2 << " ?[y/n]" << endl;
    cin >> c;
    if (c == 'y')
      tryGuess(minV,(maxV+minV)/2);
    else
      tryGuess((maxV+minV)/2,maxV);
  }
}

int main ()
{
  int number;
  number = readNumber();
  tryGuess(1,100);
}

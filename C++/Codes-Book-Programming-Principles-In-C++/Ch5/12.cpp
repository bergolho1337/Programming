#include <iostream>
#include <vector>

using namespace std;

void getDigits (vector<int> &guess, int val)
{
  int i, r;
  i = guess.size()-1;
  while (val > 0)
  {
    r = val % 10;
    guess[i] = r;
    val /= 10;
    i--;
  }

}

void checkGuess (vector<int> number, vector<int> guess, int &cow, int &bull)
{
  int i, j;
  cow = bull = 0;
  for (i = 0; i < number.size(); i++)
  {
    // Check bull
    if (number[i] == guess[i])
      bull++;
    // Check cow
    else
    {
      for (j = 0; j < guess.size(); j++)
      {
        if (number[i] == guess[j])
          cow++;
      }
    }
  }
}

int main ()
{
  int cow, bull;
  int val;
  vector<int> guess(4,0);
  // Set the number to be guessed
  vector<int> number(4,0);
  number[0] = 1;
  number[1] = 2;
  number[2] = 3;
  number[3] = 4;

  cow = bull = 0;

  while (bull != 4)
  {
    cout << "\n\t\tVVVV" << endl;
    cout << "Enter the guess:";
    cin >> val;
    getDigits(guess,val);
    checkGuess(number,guess,cow,bull);
    cout << "Cow = " << cow << " || Bull = " << bull << endl;
  }
}

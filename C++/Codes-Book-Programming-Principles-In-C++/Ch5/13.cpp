#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

#define SEED 1337

void generateNumber (vector<int> &number)
{
  int i, j, val;
  number[0] = randint(9);
  for (i = 1; i < 4; i++)
  {
    val = randint(9);
    for (j = 0; j < i; j++)
    {
      while (val == number[j])
        val = randint(9);
    }
    number[i] = val;
  }
}

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
  char c;
  vector<int> guess(4,0);
  // Set the number to be guessed
  vector<int> number(4,0);

  srand(SEED);
  while (1)
  {
    generateNumber(number);
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
    cout << "Continue? y/n >>> ";
    cin >> c;
    if (c == 'n') break;
  }
}

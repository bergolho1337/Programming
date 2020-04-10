#include <iostream>
#include <vector>
#include <string>

using namespace std;

void digitTospell (vector<string> numbers, int num)
{
  if (num < 0 || num > numbers.size())
    cout << "[-] Error! Unknown digit form!" << endl;
  else
    cout << "The digit " << num << " is spelled as " << numbers[num-1] << endl;
}

void spellTodigit (string str)
{
  cout << "The spelled digit " << str << " is in digit form ";
  if (str == "one") cout << 1 << endl;
  else if (str == "two") cout << 2 << endl;
  else if (str == "three") cout << 3 << endl;
  else if (str == "four") cout << 4 << endl;
  else if (str == "five") cout << 5 << endl;
  else if (str == "six") cout << 6 << endl;
  else if (str == "seven") cout << 7 << endl;
  else if (str == "eight") cout << 8 << endl;
  else if (str == "nine") cout << 9 << endl;
  else cout << "[-] Error! Unknown spelled digit!" << endl;
}

int main ()
{
  vector<string> numbers = {"one","two","three","four","five","six","seven","eight","nine"};
  int num;
  /*
  cout << "Give me a digit [1 to 9]: ";
  while (cin >> num)
  {
    digitTospell(numbers,num);
    cout << "Give me a digit [1 to 9]: ";
  }
  */
  string str;
  cout << endl << "Now, give me a spelled digit: ";
  while (cin >> str)
  {
    spellTodigit(str);
    cout << "Now, give me a spelled digit: ";
  }
}

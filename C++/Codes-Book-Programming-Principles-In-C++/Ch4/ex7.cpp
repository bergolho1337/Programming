#include <iostream>
#include <string>

using namespace std;

void makeOperation (int a, int b, char op)
{
  switch (op)
  {
    case '+': cout << "The sum of " << a << " and " << b << " is " << a+b << endl;
              break;
    case '-': cout << "The subtraction of " << a << " and " << b << " is " << a-b << endl;
              break;
    case '*': cout << "The product of " << a << " and " << b << " is " << a*b << endl;
              break;
    case '/': if (b == 0)
                cout << "[-] Error! Division by zero!" << endl;
              else
                cout << "The division of " << a << " and " << b << " is " << a/b << endl;
              break;
    default: cout << "[-] Error! Unknown operation!" << endl;
  }
}

int spellTodigit (string str)
{
  if (str == "one") return 1;
  else if (str == "two") return 2;
  else if (str == "three") return 3;
  else if (str == "four") return 4;
  else if (str == "five") return 5;
  else if (str == "six") return 6;
  else if (str == "seven") return 7;
  else if (str == "eight") return 8;
  else if (str == "nine") return 9;
}

void readNumbers (char c)
{
  int a, b;
  string s1, s2;
  char op;
  cout << "Enter a, b: ";
  switch (c)
  {
    case 'd': cin >> a >> b;
              break;
    case 's': cin >> s1 >> s2;
              a = spellTodigit(s1);
              b = spellTodigit(s2);
              break;
  }
  cout << "Enter the operation: ";
  cin >> op;
  makeOperation(a,b,op);
}

int main ()
{
  char c;
  cout << "You will enter digit or spelled out [d/s] ? ";
  cin >> c;
  readNumbers(c);
}

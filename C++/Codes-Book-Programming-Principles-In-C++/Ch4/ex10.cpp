#include <iostream>
#include <vector>

using namespace std;

char readPlayerInput ()
{
  char p1;
  cout << "[+] Player turn now." << endl;
  cout << "Rock/Paper/Scissor - [R/P/S] ? ";
  cin >> p1;
  return p1;
}

char readOpponentInput (vector<char> op)
{
  char p2;
  static int k = 1;
  cout << "[+] Opponent turn now." << endl;
  p2 = op[(k*23)%3];
  k++;
  return p2;
}

void makeMatch (char p1, char p2)
{
  cout << p1 << " vs " << p2 << endl;
  if (p1 == 'R')
  {
    if (p2 == 'S')
      cout << "\t[+] Player won the match!" << endl;
    else if (p2 == 'P')
      cout << "\t[-] Player lose the match!" << endl;
    else
      cout << "\t[!] Draw match!" << endl;
  }
  else if (p1 == 'S')
  {
    if (p2 == 'S')
      cout << "\t[!] Draw match!" << endl;
    else if (p2 == 'P')
      cout << "\t[-] Player won the match!" << endl;
    else
      cout << "\t[-] Player lose the match!" << endl;
  }
  else
  {
    if (p2 == 'S')
      cout << "\t[-] Player lose the match!" << endl;
    else if (p2 == 'P')
      cout << "\t[!] Draw match!" << endl;
    else
      cout << "\t[-] Player won the match!" << endl;
  }
  cout << endl;
}

int main ()
{
  vector<char> op = {'R','S','P'};
  char p1, p2;
  while (true)
  {
    p1 = readPlayerInput();
    p2 = readOpponentInput(op);
    makeMatch(p1,p2);
  }
  return 0;
}

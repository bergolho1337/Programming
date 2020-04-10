#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <chrono>

using namespace std;

void error (string msg);
void Usage (string pName);

class Roman_int
{
private:
    char letter;
public:
    Roman_int () {};
    int as_int ();
    bool is_valid (char l);

    // Output
    friend ostream& operator<< (ostream &os, Roman_int &r)
    {
        os << "Roman " << r.letter << " equals " << r.as_int() << endl;
        return os;
    }
    // Input
    friend istream& operator>> (istream &is, Roman_int &r)
    {
        char l;
        is >> l;
        if (!is || !r.is_valid(l)) error("Invalid Roman letter");
        r.letter = l;
        return is;
    }
}typedef Reading;

int Roman_int::as_int ()
{
    switch (letter)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return -1;
}

bool Roman_int::is_valid (char l)
{
    return (l == 'I' || l == 'V' || l == 'X' || l == 'L' || l == 'C' || l == 'D' || l == 'M'); 
}



void error (string msg)
{
    cout << "[-] ERROR ! " << msg << endl;
    exit(EXIT_FAILURE);
}

void Usage (string pName)
{
    cout << "--------------------------------------------------" << endl;
    cout << "Usage:> " << pName << " <nReading>" << endl;
    cout << "<nReading> = Number of readings" << endl;
    cout << "--------------------------------------------------" << endl;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
        Usage(argv[0]);
    int n = stoi(argv[1]);
    
    vector<Roman_int> romans;
    for (int i = 0; i < n; i++)
    {
        Roman_int r;
        cin >> r;
        romans.push_back(r);
    }

    for (int i = 0; i < n; i++)
        cout << romans[i];

    return 0;
}
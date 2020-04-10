#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void error (string msg)
{
    cout << "[-] ERROR ! " << msg << endl;
    exit(EXIT_FAILURE);
}

void Usage (string pName)
{
    cout << "--------------------------------------------------" << endl;
    cout << "Usage:> " << pName << " <text>" << endl;
    cout << "<text> = Line of text" << endl;
    cout << "--------------------------------------------------" << endl;
    error("Bad arguments !");
}

int main (int argc, char *argv[])
{
    
    string line;
    getline(cin,line);

    cout << line << endl;
    int a = stoi(line);

    cout << a << endl;
    
    return 0;
}
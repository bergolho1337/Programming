#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void error (string msg)
{
    cout << "[-] ERROR ! " << msg << endl;
    exit(EXIT_FAILURE);
}

int main ()
{
    ifstream in("file1.txt");
    if (!in) error("Cannot open file!");

    ifstream in2("file2.txt");
    if (!in) error("Cannot open file!");

    ofstream out("file3.txt");
    if (!out) error("Cannot open file!");

    string str;
    while (getline(in,str))
        out << str;
    while (getline(in2,str))
        out << str;

    return 0;
}
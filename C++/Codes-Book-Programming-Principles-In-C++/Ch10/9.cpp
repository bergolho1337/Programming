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

int main ()
{
    ifstream in("array1.txt");
    if (!in) error("Cannot open file!");

    ifstream in2("array2.txt");
    if (!in) error("Cannot open file!");

    vector<int> array;
    for (int value; in >> value;)
        array.push_back(value);
    for (int value; in2 >> value;)
        array.push_back(value);
    sort(array.begin(),array.end());

    for (int i = 0; i < (int)array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
    
    return 0;
}
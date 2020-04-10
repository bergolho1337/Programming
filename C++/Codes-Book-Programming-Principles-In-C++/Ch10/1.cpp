#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void error (string msg)
{
    cout << "[-] ERROR ! " << msg << endl;
    exit(EXIT_FAILURE);
}

int main ()
{
    ifstream in("numbers.txt");
    if (!in) error("Cannot open file!");

    vector<int> array;
    int sum = 0;
    for (int value; in >> value;)
        array.push_back(value), sum += value;       // Double instruction in single line

    // C++ 
    //for (int i = 0; i < static_cast<int>(array.size()); i++)
    //    cout << array[i] << endl;
    // C++ 11
    for (auto value : array)
        cout << value << endl;
    
    cout << "Sum = " << sum << endl;

    return 0;
}
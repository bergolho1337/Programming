// 1 - Write a program that reads a text file and covnerts its input to all lowercase producing a new file.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
    ifstream is("input_file_1.txt");
    ofstream os("output_file_1.txt");

    // Reading each line of the file
    string line;
    while ( getline(is,line) )
    {
        //cout << line << endl;

        // Pass through the string converting to lowercase each character
        for (char &c : line)
            c = tolower(c); 

        os << line << endl;
    }

    os.close();
    is.close();
}
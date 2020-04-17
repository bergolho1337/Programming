// 10. Write a function vector<string> split (const string &s) that returns a vector of whitespaced separated substrings from teh argument s

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> split (const string &s)
{
    vector<string> substrings;

    // Put the string into a stringstream
    stringstream ss(s);
    
    // Read each word from the string. 
    // By default the stringstream will separate the words using whitespaces
    for (string word; ss >> word; )
    {
        substrings.push_back(word);    
    }

    return substrings;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./10 <filename>" << endl;
        exit(EXIT_FAILURE);
    }

    string filename(argv[1]);

    // Open the file for reading
    ifstream is(filename);
    if (!is)
    {
        cerr << "[-] ERROR! Cannot open filename " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Pass through each line of the file
    string line;
    int counter = 1;

    while (getline(is,line))
    {
        cout << "Line number " << counter << endl;
        
        vector<string> substrings = split(line);

        for (uint32_t i = 0; i < substrings.size(); i++)
            cout << "\t" << substrings[i] << endl;

        cout << endl;
        counter++;
    }

    is.close();

    return 0;
}

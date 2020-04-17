// 11. Write a function vector<string> split (const string &s, const string &w) that returns a vector of whitespace separated substrings from the argument s, where whitespace is defined
//     as "ordinary whitespace" plus the characters in w. 

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool is_whitespace (const char c, const string &whitespaces)
{
    for (char w : whitespaces)
    {
        if (c == w)
            return true;
    }
    return false;
}

vector<string> split (const string &s, const string &w)
{
    vector<string> substrings;

    string processed_s;
    // First of all we change every characters of the line that is inside the whitespace set to whitespace
    for (char c : s)
    {
        if (is_whitespace(c,w))
            c = ' ';
        processed_s += c;
    }
    //cout << processed_s << endl;

    // Put the processed string into a stringstream
    stringstream ss(processed_s);
    
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
        cout << "Usage:> ./11 <filename>" << endl;
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

    // Define which arecharacters will be consider whitespaces
    string whitespaces = ";,.:?!(){}[]<>/&^$@#%*-|~'";

    // Pass through each line of the file
    string line;
    int counter = 1;

    while (getline(is,line))
    {

        cout << "Line number " << counter << endl;
        
        vector<string> substrings = split(line,whitespaces);

        for (uint32_t i = 0; i < substrings.size(); i++)
            cout << "\t" << substrings[i] << endl;

        cout << endl;
        counter++;
    }

    is.close();

    return 0;
}

// 3- Write a program that removes all vowels from a file. For example, "Once upon a time!" becomes "nc pn tm!".

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

bool is_vowel (char c)
{
    static const string vowels = "aeiouAEIOU";

    for (char w : vowels)
        if (c == w) return true;
    return false;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./3 <filename>" << endl;
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

    string line;
    int counter = 1;
    // Pass through each line of the file
    while (getline(is,line))
    {
        // Put the line into a stringstream
        stringstream ss(line);
        // Read each word from the line
        for (string word; ss >> word; )
        {
            // Eliminate punctuation
            string processed_word;
            for (char &ch : word)
            {
                if (!is_vowel(ch))
                    processed_word += ch;
            }
            cout << processed_word << " ";
        }
        cout << endl;
        counter++;
    }

    is.close();

    return 0;
}

// 6- Write a program taht replaces punctuation with whitespaces. Consider .(dot), ;(semicolon), ,(comma), ?(question mark), -(dash), '(single quote) punctuation characters. Don`t modify characters within a pair of double quotes (")
//    For example, " - don't use the as-if rule." becomes "   don t use the as if rule ".

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

bool is_punctuation (char c)
{
    static const string punctuations = ".;,?-'!";

    for (char w : punctuations)
        if (c == w) return true;
    return false;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./6 <filename>" << endl;
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
                if (is_punctuation(ch))
                    processed_word += ' ';
                else
                    processed_word += tolower(ch);
            }
            cout << processed_word << " ";
        }
        cout << endl;
        counter++;
    }

    is.close();

    return 0;
}

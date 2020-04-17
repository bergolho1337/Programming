// 7- Modify the program from the previous exercise so that it replaces dont`t with do not, can't with cannot, etc.; leaves hyphens within words intact; and converts all characters to lower case.

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

void parse_contractions (string &s)
{
    if (s == "don't")
        s = "do not";
    else if (s == "doesn't")
        s = "does not";
    else if (s == "won't")
        s = "will not";
    else if (s == "wouldn't")
        s = "would not";
    else if (s == "mustn't")
        s = "must not";
    else if (s == "can't")
        s = "cannot";
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./7 <filename>" << endl;
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
            // Change contractions ("don't" -> "do not")
            parse_contractions(word);

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

// 8- Use the program from the previous exercise to make a dictionary. Run the result on a multi-page text file. 

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool is_punctuation (char c)
{
    static const string punctuations = ".;,?-'!'\"()[]{}:";

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
    else if (s == "didn't")
        s = "did not";
    else if (s == "won't")
        s = "will not";
    else if (s == "wouldn't")
        s = "would not";
    else if (s == "mustn't")
        s = "must not";
    else if (s == "can't")
        s = "cannot";
    else if (s == "hadn't")
        s = "had not";
    else if (s == "haven't")
        s = "have not";
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./8 <filename>" << endl;
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

    // Dictionary will be a hash map, which stores the word and the number of times that word appeared in the text
    map<string,int> the_dictionary;

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
                // Only process letters
                if (!is_punctuation(ch))
                    processed_word += tolower(ch);
            }

            // Try to insert the word into the dictionary
            if (the_dictionary.count(processed_word) == 0)
                the_dictionary[processed_word] = 1;
            else
                the_dictionary[processed_word]++;
        }
        counter++;
    }

    is.close();

    for (auto it = the_dictionary.begin(); it != the_dictionary.end(); it++)
        cout << "|| Key = " << it->first << " || Value = " << it->second << " ||" << endl;
    cout << "There are " << the_dictionary.size() << " words in the dictionary" << endl; 

    return 0;
}

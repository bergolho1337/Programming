// 14. Write a program that reads a text file and writes out how many characters of each character classification are in the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./12 <filename>" << endl;
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

    uint32_t total_characters = 0;
    uint32_t counter_spaces = 0;
    uint32_t counter_alpha = 0;
    uint32_t counter_digit = 0;
    uint32_t counter_upper = 0;
    uint32_t counter_lower = 0;
    uint32_t counter_punct = 0;

    // Pass through each line of the file (this will take care of the memory issue)
    string line;
    int counter = 1;
    while (getline(is,line))
    {
        // Read each character from the line
        for (char ch : line)
        {
            if (isspace(ch))
                counter_spaces++;
            if (isalpha(ch))
                counter_alpha++;
            if (isdigit(ch))
                counter_digit++;
            if (isupper(ch))
                counter_upper++;
            if (islower(ch))
                counter_lower++;
            if (ispunct(ch))
                counter_punct++;

            total_characters++;
        }

        counter++;
    }

    cout << "Number of spaces = " << counter_spaces << endl;
    cout << "Number of alphanumerical = " << counter_alpha << endl;
    cout << "Number of digits = " << counter_digit << endl;
    cout << "Number of uppercase = " << counter_upper << endl;
    cout << "Number of lowercase = " << counter_lower << endl;
    cout << "Number of punctuation = " << counter_punct << endl;
    cout << "Total number of characters = " << total_characters << endl;

    is.close();

    return 0;
}

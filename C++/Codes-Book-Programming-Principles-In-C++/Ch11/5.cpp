// 5- Write a program that reads strings and for each string outputs the character classification of each character, as defined by the character classification functions.
//    Note that a character can have several classifications (e.g., x is both a letter and an alphanumeric).

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./5 <filename>" << endl;
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

    string line, base_name;
    int counter = 1;
    // Pass through each line of the file
    while (getline(is,line))
    {
        cout << "Checking string:> " << line << endl;
        for (char ch : line)
        {
            string char_type = "";

            if (isspace(ch))
                char_type += " whitespace";
            if (isalpha(ch))
                char_type += " letter";
            if (isdigit(ch))
                char_type += " digit";
            if (isupper(ch))
                char_type += " uppercase";
            if (islower(ch))
                char_type += " lowercase";
            if (isalnum(ch))
                char_type += " alphanumeric";
            
            cout << "\tCharacter '" << ch << "' --> " << char_type << endl;
        }
    }

    is.close();

    return 0;
}

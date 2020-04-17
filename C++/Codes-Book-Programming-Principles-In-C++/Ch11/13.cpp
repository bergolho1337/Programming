// 13. Reverse the order of words (defined as whitespaces separated strings) in a file. For example, Norwegian Blue parrot becomes parrot Blue Norwegian.

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

    // Pass through each line of the file (this will take care of the memory issue)
    string line;
    int counter = 1;
    while (getline(is,line))
    {
        // Define a vector that will store all the characters from the file
        vector<string> line_content;

        // Put the string into a stringstream
        stringstream ss(line);

        // Read each word from the line
        for (string word; ss >> word;)
        {
            line_content.push_back(word);
        }

        // Output this line in reverse order
        reverse(line_content.begin(),line_content.end());

        for (uint32_t i = 0; i < line_content.size(); i++)
            cout << line_content[i] << " ";
        cout << endl;

        counter++;
    }

    is.close();

    return 0;
}

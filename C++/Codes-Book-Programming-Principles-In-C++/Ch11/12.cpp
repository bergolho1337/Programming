// 12. Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa.

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

    // Define a vector that will store all the characters from the file
    vector<char> file_content;

    // Pass through each line of the file
    string line;
    int counter = 1;
    while (getline(is,line))
    {
        for (char ch : line)
            file_content.push_back(ch);
        
        counter++;
    }

    // Reverse the order of the characters
    reverse(file_content.begin(),file_content.end());

    for (uint32_t i = 0; i < file_content.size(); i++)
    {
        cout << file_content[i];
    }
    cout << endl;

    is.close();

    return 0;
}

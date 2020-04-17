// 16. Write a program that reads a file of whitespace-separated numbers and output them in order (lowest value first), one per line.
//     Write a value only once, and if it occurs more than once write the count of its occurrences on its line.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./16 <filename>" << endl;
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

    map<double,uint32_t> numbers_table;

    // Pass through each line of the file (this will take care of the memory issue)
    string line;
    uint32_t line_counter = 1;
    while (getline(is,line))
    {
        stringstream ss(line);

        for (string string_number; ss >> string_number;)
        {
            stringstream parser(string_number);

            double number;
            parser >> number;

            if (numbers_table.count(number) == 0)
                numbers_table[number] = 1;
            else
                numbers_table[number]++;

        }

        line_counter++;
    }

    is.close();

    map<double,uint32_t>::iterator it;
    for (it = numbers_table.begin(); it != numbers_table.end(); ++it)
    {
        if (it->second == 1)
            cout << it->first << endl;
        else
            cout << it->first << " " << it->second << endl;
    }
        


    return 0;
}

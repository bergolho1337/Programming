// 15. Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers using scientific format and precision 8 in four fields of 20 characters per line.

#include <iostream>
#include <iomanip>
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
        cout << "Usage:> ./15 <filename>" << endl;
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

    // Configure the precision
    cout << scientific << setprecision(8);

    // Pass through each line of the file (this will take care of the memory issue)
    string line;
    uint32_t line_counter = 1;
    while (getline(is,line))
    {
        uint32_t counter = 0;
        stringstream ss(line);

        for (string string_number; ss >> string_number;)
        {
            // If is the last field break a line
            if (counter == 4)
            {
                counter = 0;
                cout << endl;
            }

            stringstream parser(string_number);

            double number;
            parser >> number;

            cout << setw(20) << number << " ";
            counter++;
        }

        line_counter++;
    }
    cout << endl;

    is.close();

    return 0;
}

// 4- Write a program that reads several integers in any combination of octal, decimal or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and 
//    converts them to decimal form. Then your program should output the values in properly spaced columns like this:
//
//      0x43     hexadecimal converts to         67 decimal
//      0123           octal converts to         83 decimal
//        65         decimal converts to         65 decimal


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int str_to_int (string s, string base)
{
    stringstream is(s);
    
    int value;
    if (base == "hexadecimal")
        is >> hex >> value;
    else if (base == "octal")
        is >> oct >> value;
    else
        is >> value;

    return value;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./4 <filename>" << endl;
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
        if (line.find("0x") != string::npos)
            base_name = "hexadecimal";    
        else if (line[0] == '0')
            base_name = "octal";
        else
            base_name = "decimal";

        int value = str_to_int(line,base_name);
        
        cout << setw(10) << line << " " << setw(15) << base_name << setw(10) << " converts to " << setw(10) << value << " decimal" << endl;
    }

    is.close();

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

bool leapyear (int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

int main (int argc, char *argv[])
{
    int year = stoi((string)argv[1]);
    if (leapyear(year))
        cout << "[+] The year " << year << " is a leap year !" << endl;
    else
        cout << "[-] The year " << year << " is NOT a leap year !" << endl;
    return 0;
}
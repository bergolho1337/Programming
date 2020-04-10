#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <chrono>

using namespace std;

struct Reading
{
    int hour;
    double temperature;
}typedef Reading;

void error (string msg)
{
    cout << "[-] ERROR ! " << msg << endl;
    exit(EXIT_FAILURE);
}

void Usage (string pName)
{
    cout << "--------------------------------------------------" << endl;
    cout << "Usage:> " << pName << " <nReading>" << endl;
    cout << "<nReading> = Number of readings" << endl;
    cout << "--------------------------------------------------" << endl;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
        Usage(argv[0]);
    int n = stoi(argv[1]);
    
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> hours(0,23);
    uniform_int_distribution<int> temperatures(-273,273);

    ofstream out("raw_temps.txt");
    for (int i = 0; i < n; i++)
        out << hours(generator) << " " << temperatures(generator) << endl;

    return 0;
}
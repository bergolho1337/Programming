#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <chrono>

using namespace std;

struct Reading
{
    int hour;
    int temperature;
    Reading (int h, int t) :  hour(h), temperature(t) {};
}typedef Reading;

void error (string msg)
{
    cout << "[-] ERROR ! " << msg << endl;
    exit(EXIT_FAILURE);
}

void Usage (string pName)
{
    cout << "--------------------------------------------------" << endl;
    cout << "Usage:> " << pName << endl;
    cout << "--------------------------------------------------" << endl;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 0)
        Usage(argv[0]);
    
    ifstream in("raw_temps.txt");
    vector<Reading> reads;

    for (int hour, temp; in >> hour >> temp;)
        reads.push_back(Reading(hour,temp));

    double mean = 0;
    for (auto read : reads)
        mean += read.temperature;
    mean /= static_cast<double>(reads.size());
    int median = reads[reads.size()/2].temperature;
    
    cout << "Mean = " << mean << endl;
    cout << "Median = " << median << endl;

    return 0;
}
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
    char unit;
    Reading (int h, int t, char u) :  hour(h), temperature(t) , unit(u) {};
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
    error("Bad parameters !");
}

double celsiusTofarenheit (double c)
{
    return c*1.8 + 32.0;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
        Usage(argv[0]);
    int n = stoi(argv[1]);
    
    char u[2] = {'c','f'};
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> hours(0,23);
    uniform_int_distribution<int> temperatures(-273,273);
    uniform_int_distribution<int> unit(0,1);

    ofstream out("raw_temps2.txt");
    for (int i = 0; i < n; i++)
        out << hours(generator) << " " << temperatures(generator) << " " << u[unit(generator)] <<  endl;
    out.close();
    
    ifstream in("raw_temps2.txt");
    vector<Reading> reads;

    char uni;
    int hour;
    double temp;
    while (in >> hour >> temp >> uni)
    {
        if (uni == 'c')
            temp = celsiusTofarenheit(temp), uni = 'f';
        reads.push_back(Reading(hour,temp,uni));
    }
    in.close();

    for (int i = 0; i < (int)reads.size(); i++)
        cout << reads[i].hour << " " << reads[i].temperature << " " << reads[i].unit << endl;
        

    return 0;
}
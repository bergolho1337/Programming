#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Data
{
    int largest;
    int smallest;
    double mean;
    int median;
}typedef Data;

Data computeData (vector<int> v)
{
    int n = (int)v.size();
    Data data;
    data.mean = 0.0;
    data.smallest = data.largest = v[0];
    data.median = v[n/2];
    for (int i = 0; i < n; i++)
    {
        data.smallest = min(data.smallest,v[i]);
        data.largest = max(data.largest,v[i]);
        data.mean += v[i];
    }
    data.mean /= (double)n;
    return data;
}

int main ()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    Data data = computeData(v);
    cout << "Largest = " << data.largest << endl;
    cout << "Smallest = " << data.smallest << endl;
    cout << "Mean = " << data.mean << endl;
    cout << "Median = " << data.median << endl;
    return 0;
}
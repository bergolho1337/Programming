#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> computeCharacters (vector<string> v)
{
    vector<int> num_c;
    for (int i = 0; i < (int)v.size(); i++)
        num_c.push_back((int)v[i].size());
    return num_c;
}

string findLargest (vector<string> v)
{
    string largest = v[0];
    int maxV = (int)v.size();
    for (string tmp : v)
    {
        if ((int)tmp.size() > maxV)
        {
            largest = tmp;
            maxV = (int)tmp.size();
        }
    }
    return largest;
}

string findSmallest (vector<string> v)
{
    string smallest = v[0];
    int minV = (int)v.size();
    for (string tmp : v)
    {
        if ((int)tmp.size() < minV)
        {
            smallest = tmp;
            minV = (int)tmp.size();
        }
    }
    return smallest;
}

void findFirstAndLast (vector<string> v, string &first, string &last)
{
    int n = (int)v.size();
    sort(v.begin(),v.end());
    first = v[0];
    last = v[n-1];
}

int main ()
{
    string first, last;
    vector<string> v;
    v.push_back("ABC");
    v.push_back("AB");
    v.push_back("A");
    vector<int> num_c = computeCharacters(v);
    string largest = findLargest(v);
    string smallest = findSmallest(v);
    findFirstAndLast(v,first,last);
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i] << " " << num_c[i] << endl;
    }
    cout << "Largest = " << largest << endl;
    cout << "Smallest = " << smallest << endl;
    cout << "First = " << first << endl;
    cout << "Last = " << last << endl;
    return 0;
}
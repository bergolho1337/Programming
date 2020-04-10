#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print (string label, vector<int> v)
{
    cout << label << endl;
    for (int tmp : v)
        cout << tmp << endl;
    cout << endl;
}

int main ()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    print("Vetor v",v);
    return 0;
}
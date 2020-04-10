#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> reverse1 (vector<int> v)
{
    vector<int> v_rev;
    for (int i = (int)v.size()-1; i >= 0; i--)
        v_rev.push_back(v[i]);
    return v_rev;
}

vector<int> reverse2 (vector<int> v)
{
    int n = (int)v.size();
    for (int i = 0; i < n/2; i++)
        swap(v[i],v[n-i-1]);
    return v;
}

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
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    print("Vector v",v);
    vector<int> v_rev = reverse1(v);
    print("Reverse vector v1",v_rev);

    vector<int> v_rev2 = reverse2(v);
    print("Reverse vector v2",v_rev2);

    return 0;
}
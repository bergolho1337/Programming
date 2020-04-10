#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> reverse1 (vector<string> v)
{
    vector<string> v_rev;
    for (int i = (int)v.size()-1; i >= 0; i--)
        v_rev.push_back(v[i]);
    return v_rev;
}

vector<string> reverse2 (vector<string> v)
{
    int n = (int)v.size();
    for (int i = 0; i < n/2; i++)
        swap(v[i],v[n-i-1]);
    return v;
}

void print (string label, vector<string> v)
{
    cout << label << endl;
    for (string tmp : v)
        cout << tmp << endl;
    cout << endl;
}

int main ()
{
    vector<string> v;
    v.push_back("Albert");
    v.push_back("Bohr");
    v.push_back("Gauss");
    v.push_back("Tesla");
    v.push_back("Weistrass");

    print("Vector v",v);
    vector<string> v_rev = reverse1(v);
    print("Reverse vector v1",v_rev);

    vector<string> v_rev2 = reverse2(v);
    print("Reverse vector v2",v_rev2);

    return 0;
}
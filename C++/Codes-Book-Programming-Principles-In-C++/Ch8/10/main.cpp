#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxv (vector<int> v)
{
    int maxV = v[0];
    for (int tmp : v)
        maxV = max(tmp,maxV);
    return maxV;
}

int main ()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(192);
    v.push_back(3);
    cout << "Largest element in vector v is: " << maxv(v) << endl;
    return 0;
}
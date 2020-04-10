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

void fibonacci (int x, int y, vector<int> &fib, int n)
{
    fib.push_back(x);
    fib.push_back(y);
    for (int i = 2; i < n; i++)
        fib.push_back(fib[i-2]+fib[i-1]);
}

int main ()
{
    int x, y, n;
    vector<int> fib;
    
    cout << "Enter the number of Fibonacci numbers: ";
    cin >> n;
    cout << "Enter the values of x and y: ";
    cin >> x >> y;
    
    fibonacci(x,y,fib,n);

    print("Fibonacci numbers",fib);
    
    return 0;
}
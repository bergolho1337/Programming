#include <iostream>

using namespace std;

void swap_v (int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_r (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Never is going to run.
// Read-only variable is not assignable
/*
void swap_cr (const int &a, const int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
*/

int main ()
{
    int x = 7;
    int y = 9;
    cout << "x = " << x << " y = " << y << endl;
    swap_v(x,y);
    cout << "x = " << x << " y = " << y << endl;
    
    cout << "x = " << x << " y = " << y << endl;
    swap_r(x,y);
    cout << "x = " << x << " y = " << y << endl;

    const int cx = 7;
    const int cy = 9;
    cout << "x = " << x << " y = " << y << endl;
    swap_v(cx,cy);
    cout << "x = " << x << " y = " << y << endl;
    
    // Const value cannot be changed
    //cout << "x = " << x << " y = " << y << endl;
    //swap_r(cx,cy);
    //cout << "x = " << x << " y = " << y << endl;

    double dx = 7.7;
    double dy = 9.9;
    cout << "x = " << x << " y = " << y << endl;
    swap_v(dx,dy);
    cout << "x = " << x << " y = " << y << endl;

    // Incompatible types
    //cout << "x = " << x << " y = " << y << endl;
    //swap_r(dx,dy);
    //cout << "x = " << x << " y = " << y << endl;

}
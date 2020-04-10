#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

int main ()
{
  try
  {
    //Cout << "Sucess!\n";
    //cout << "Sucess!\n";

    //cout << "Sucess!\n;
    //cout << "Sucess!\n";

    //cout << "Sucess" << !\n"
    //cout << "Sucess" << "!\n";

    //cout << sucess << '\n';
    //cout << "Sucess!" << '\n';

    //string res = 7; vector<int> v(10); v[5] = res; cout << "Sucess!\n";
    //int res = 7; vector<int> v(10); v[5] = res; cout << "Sucess!\n";

    //vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Sucess!\n";
    //vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Sucess!\n";

    //if (cond) cout << "Sucess!\n"; else cout << "Fail!\n";
    //if (1) cout << "Sucess!\n"; else cout << "Fail!\n";

    //bool c = false; if (c) cout << "Sucess!\n"; else cout << "Fail!\n";
    //bool c = true; if (c) cout << "Sucess!\n"; else cout << "Fail!\n";

    //string s = "ape"; boo c = "fool"<s; if (c) cout << "Sucess!\n";
    //string s = "ape"; bool c = "fool">s; if (c) cout << "Sucess!\n";

    //string s = "ape"; if (s=="fool") cout << "Sucess\n!";
    //string s = "ape"; if (s=="ape") cout << "Sucess!\n";

    //string s = "ape"; if (s=="ape") cout < "Sucess!\n"
    //string s = "ape"; if (s=="ape") cout << "Sucess!\n"

    //string s = "ape"; if (s+"fool") cout << "Sucess!\n";
    //string s = "ape"; if (s+"fool"=="apefool") cout << "Sucess!\n";

    //vector<char> v(5); for (int i=0; 0<v.size(); ++i); cout << "Sucess!\n";
    //vector<char> v(5); for (int i=0; i<v.size(); ++i); cout << "Sucess!\n";

    //int x = 2; double d = 5/x-2; if(d==2*x+0.5) cout << "Sucess!\n";
    double x = 2.0; double d= 5/x+2.0; if(d==2*x+0.5)cout << "Sucess!\n";

    return 0;
  }
  catch(exception &e)
  {
    cerr << "error: " << e.what() << endl;
    return 1;
  }
  catch(...)
  {
    cerr << "Oops: unknown exception" << endl;
    return 2;
  }
}

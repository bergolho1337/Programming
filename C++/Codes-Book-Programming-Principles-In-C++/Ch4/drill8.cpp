#include <iostream>
#include <string>

using namespace std;

int main ()
{
  double value;
  string unit;

  cout << "Enter a value and a unit(cm/m/in/ft):" << endl;
  while (cin >> value >> unit)
  {
    cout << "Value entered = " << value << " " << unit << endl;
    cout << "Converting ..." << endl;
    if (unit == "cm")
    {
       cout << "\tm = " << value/100.0 << endl;
       cout << "\tin = " << value/2.54 << endl;
       cout << "\tft = " << value/(2.54*12.0) << endl;
    }
    else if (unit == "m")
    {
      cout << "\tcm = " << value*100.0 << endl;
      cout << "\tin = " << value*100.0/2.54 << endl;
      cout << "\tft = " << value*100.0/(2.54*12.0) << endl;
    }
    else if (unit == "in")
    {
      cout << "\tcm = " << value*2.54 << endl;
      cout << "\tm = " << value*2.54/100.0 << endl;
      cout << "\tft = " << value/12.0 << endl;
    }
    else if (unit == "ft")
    {
      cout << "\tcm = " << value*12.0*2.54 << endl;
      cout << "\tm = " << value*12.0*2.54/100.0 << endl;
      cout << "\tin = " << value*12.0 << endl;
    }
    else
    {
      cout << "[-] ERROR! Invalid unit!" << endl;
    }
  }
}

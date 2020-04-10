#include <iostream>
#include <string>

using namespace std;

int main ()
{
  int cont;
  double value, conv;
  double max, min;
  string unit;
  double sum = 0.0;
  max = -1.0e+100;
  min = 1.0e+100;
  cont = 0;

  cout << "Enter a value and a unit(cm/m/in/ft):" << endl;
  while (cin >> value >> unit)
  {
    cout << "Value entered = " << value << " " << unit << endl;
    cout << "Converting ..." << endl;
    if (unit == "cm")
    {
       conv = value/100.0;
       sum += conv;
       if (conv > max)
        max = conv;
       if (conv < min)
        min = conv;
       cont++;
       cout << "\tm = " << conv << endl;
    }
    else if (unit == "m")
    {
      conv = value;
      sum += conv;
      if (conv > max)
       max = conv;
      if (conv < min)
       min = conv;
      cont++;
      cout << "\tm = " << conv << endl;
    }
    else if (unit == "in")
    {
      conv = value*2.54/100.0;
      sum += conv;
      if (conv > max)
       max = conv;
      if (conv < min)
       min = conv;
      cont++;
      cout << "\tm = " << conv << endl;
    }
    else if (unit == "ft")
    {
      conv = value*12.0*2.54/100.0;
      sum += conv;
      if (conv > max)
       max = conv;
      if (conv < min)
       min = conv;
      cont++;
      cout << "\tm = " << value*12.0*2.54/100.0 << endl;
    }
    else
    {
      cout << "[-] ERROR! Invalid unit!" << endl;
    }
  }
  cout << "===============================================================" << endl;
  cout << "Maximum value = " << max << " m." << endl;
  cout << "Minimum value = " << min << " m." << endl;
  cout << "Number of values readed = " << cont << endl;
  cout << "Sum of the values = " << sum << " m." << endl;
  return 0;
}

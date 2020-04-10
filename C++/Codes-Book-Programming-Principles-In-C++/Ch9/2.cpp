#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Name_pairs
{
private:
    vector<string> names;
    vector<double> ages;

public:
    class Invalid { };
    void read_names ();
    void read_ages ();
    void print ();
    void sort ();
};

void Name_pairs::read_names ()
{
    string name;
    cout << "[!] Reading names ..." << endl;
    while (cin >> name)
    {
        if (name == "-1") break;
        names.push_back(name);
    }
        
}

void Name_pairs::read_ages ()
{
    double age;
    if (names.empty())
    {
        cout << "[-] ERROR ! No names found !" << endl;
        throw Invalid{};
    }
    cout << "[!] Reading ages ..." << endl;
    for (string name : names)
    {
        cout << "Age for name '" << name << "'" << endl;
        cin >> age;
        ages.push_back(age);
    }
}

void Name_pairs::print ()
{
    cout << "[!] Printing Name_pairs ..." << endl;
    for (int i = 0; i < (int)names.size(); i++)
        cout << names[i] << " " << ages[i] << endl;
}

void Name_pairs::sort ()
{
    cout << "[!] Sorting Name_pairs ..." << endl;
    for (int i = 0; i < (int)names.size(); i++)
    {
        for (int j = i+1; j < (int)names.size(); j++)
        {
            if (names[j] < names[i])
            {
                swap(names[j],names[i]);
                swap(ages[j],ages[i]);
            }
        }
    }
}

int main ()
{
    Name_pairs np;
    np.read_names();
    np.read_ages();
    np.print();
    np.sort();
    np.print();

    return 0;
}
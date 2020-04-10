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
    vector<string> getNames () { return names; }
    vector<double> getAges () { return ages; }
    void read_names ();
    void read_ages ();
    void sort ();

};

bool operator== (Name_pairs &a, Name_pairs &b)
{
    vector<string> names_a = a.getNames();
    vector<string> names_b = b.getNames();
    vector<double> ages_a = a.getAges();
    vector<double> ages_b = b.getAges();
    if (names_a.size() != names_b.size())
        return false;
    else
    {
        for (int i = 0; i < (int)names_a.size(); i++)
        {
            if (names_a[i] != names_b[i] || ages_a[i] != ages_b[i])
                return false;
        }
        return true;
    }
}

bool operator!= (Name_pairs &a, Name_pairs &b)
{
    vector<string> names_a = a.getNames();
    vector<string> names_b = b.getNames();
    vector<double> ages_a = a.getAges();
    vector<double> ages_b = b.getAges();
    if (names_a.size() != names_b.size())
        return true;
    else
    {
        for (int i = 0; i < (int)names_a.size(); i++)
        {
            if (names_a[i] != names_b[i] || ages_a[i] != ages_b[i])
                return true;
        }
        return false;
    }
}

ostream& operator<< (ostream &os, Name_pairs &a)
{
    vector<string> names = a.getNames();
    vector<double> ages = a.getAges();

    for (int i = 0; i < (int)names.size(); i++)
        os << names[i] << " " << ages[i] << endl;
    
    return os;
}

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
    Name_pairs np1, np2;
    np1.read_names();
    np1.read_ages();
    cout << np1 << endl;
    
    np2.read_names();
    np2.read_ages();
    cout << np2 << endl;

    if (np1 == np2)
        cout << "[+] The Name_pairs are equal" << endl;
    else
        cout << "[-] The Name_pairs are NOT equal" << endl;

    if (np1 != np2)
        cout << "[+] The Name_pairs are different" << endl;
    else
        cout << "[-] The Name_pairs are NOT different" << endl;
    //np1.sort();
    //np1.print();

    return 0;
}
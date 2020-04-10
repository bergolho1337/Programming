#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
}typedef Person;

bool compare (Person a, Person b)
{
    return (a.name < b.name);
}

void readInput (vector<Person> &persons)
{
    int n;
    Person person;
    cout << "Enter the number of persons to read: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Name " << i+1 << ": ";
        cin >> person.name;
        persons.push_back(person);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Age of person " << i+1 << ": ";
        cin >> persons[i].age;
    }
}

void print (string label, vector<Person> v)
{
    cout << label << endl;
    for (Person tmp : v)
        cout << tmp.name << " " << tmp.age << endl;
    cout << endl;
}

int main ()
{
    vector<Person> persons;
    readInput(persons);

    print("Vector persons before sorting",persons);
    sort(persons.begin(),persons.end(),compare);
    print("Vector persons after sorting",persons);

    return 0;
}
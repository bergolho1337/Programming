#include <iostream>
#include<cstdlib>
#include <string>

using namespace std;

void simple_error (string s)
{
	cerr << s << endl;
	exit(1);
}

int main ()
{
	string name, friend_name;
	char friend_sex;
	int age;

	cout << "Enter the name of the person you want to write to:\n";
	cin >> name;
	cout << "Enter the name of the friend:\n";
	cin >> friend_name;
	cout << "Enter the sex of your friend (m=male/f=female):\n";
	cin >> friend_sex;
	cout << "Enter the age of your friend:\n";
	cin >> age;

	// Write the letter
	cout << "Dear " << name << "," << endl;
	cout << "How are you ? I am fine. I miss you!" << endl;
	cout << "Have you seen " << friend_name << " lately ?" << endl;
	if (friend_sex == 'm')
		cout << "Please ask him to call me." << endl;
	if (friend_sex == 'f')
		cout << "Please ask her to call me." << endl;
	if (age > 0 && age < 111)
		cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
	else
		simple_error("you're kidding!");
	if (age < 12)
		cout << "Next year you will be " << age+1 << endl;
	if (age == 17)
		cout << "Next year you be able to vote." << endl;
	if (age > 70)
		cout << "I hope you enjoy retirement." << endl;
	cout << "Yours sincerily," << endl << endl;
	cout << "Lucas" << endl;
	return 0;
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calculate_maximum_length(vector<string> array)
{
    vector<int> sizes;
    for (int i = 0; i < array.size(); i++)
        sizes.push_back(array[i].size());
    
    return *max_element(sizes.begin(),sizes.end());
}

void calculate_field_sizes(vector<string> first_names, vector<string> last_names, vector<string> phone_numbers, vector<string> email_adresses, int sizes[])
{
    sizes[0] = calculate_maximum_length(first_names);
    sizes[1] = calculate_maximum_length(last_names);
    sizes[2] = calculate_maximum_length(phone_numbers);
    sizes[3] = calculate_maximum_length(email_adresses);
}

int main ()
{
    int birth_date = 1993;

    cout << "Dec" << "\t" << "Hex" << "\t" << "Oct" << endl;
    //cout << dec << birth_date << "\t" << hex << birth_date << "\t" << oct << birth_date << endl;                  // Questions 2, 3 and 4
    cout << showbase << dec << birth_date << "\t" << hex << birth_date << "\t" << oct << birth_date << endl;        // Question 7

    int age = 26;
    // This will be buggy since the 'oct' flag persisted after the output (Question 5)
    //cout << "Age " << age << endl;
    cout << "Age " << dec << age << endl;       // Correct one!           (Question 6)

    cout << endl;
    //int a, b, c, d;                                               // Question 8
    //cout << "Write your output: (oct hex dec dec)" << endl;
    //cin >> a >> oct >> b >> hex >> c >> d;                          // This will read 'a' as decimal, 'b' as an octal and 'c' and 'd' as hexa.
    //cout << a << "\t" << b << "\t" << c << "\t" << d << endl;       // If the input is given as {1234 1234 1234 1234} it will consider the number 1234 on their respective bases and convert the number to it. 
                                                                    // For instance dec{1234} = 1234 || oct{1234} = 668 || hex{1234} = 4660
                                                                    // If we want to print: 1234 1234 1234 1234, we should give the following input {1234 2322 4d2 4d2}
    cout << endl;        
    double float_number = 12345567.89;                                      // Question 9
    cout << "defaultfloat = " << float_number << endl;
    cout << "fixed = " << fixed << float_number << endl;
    cout << "scientific = " << scientific << float_number << endl;
    cout << "defaultfloat = " << defaultfloat << float_number << endl;
    // Both 'defaultfloat' and 'scientific' will give the most accurate value to the user.
    // Basically the 'defaultfloat' format chooses between 'scientific' and 'fixed' formats to present the user with the most accurate representation of a floating-point value within the precision of the 'defaultfloat' format, which
    // defaults to six total digits.

    cout << endl;                                                       // Question 10
    vector<string> first_names = {"Lucas","Tales","Jonata","Joao","Joao"};
    vector<string> last_names = {"Berg","Lima","Jefferson","Marcos","Gabriel"};
    vector<string> phone_numbers = {"1111-1111","2222-2222","3333-3333","4444-4444","5555-5555"};
    vector<string> email_adresses = {"lucas.berg@cpp.br","tales.lima@cpp.br","jonata.jefferson@cpp.br","joao.marcos@cpp.br","joao.gabriel@cpp.br"};

    // Get the best width for each field
    int sizes[4];
    calculate_field_sizes(first_names,last_names,phone_numbers,email_adresses,sizes);

    cout << setw(sizes[0]+8) << "First name" << setw(sizes[1]+8) << " Last name" << setw(sizes[2]+8) << " Phone number" << setw(sizes[3]+8) << " Email adress" << endl;   
    for (int i = 0; i < first_names.size(); i++)
        cout << setw(sizes[0]+8) << first_names[i] << setw(sizes[1]+8) << last_names[i] << setw(sizes[2]+8) << phone_numbers[i] << setw(sizes[3]+8) << email_adresses[i] << endl;

    return 0;
}
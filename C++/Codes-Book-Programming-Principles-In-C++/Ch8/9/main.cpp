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

double computeIndex (vector<double> price, vector<double> weight)
{
    if ((int)price.size() != (int)weight.size())
    {
        cout << "[-] The vectors price and weight are not with the same size." << endl;
        return -1;
    }
    else
    {
        double index = 0;
        for (int i = 0; i < (int)price.size(); i++)
            index += price[i]*weight[i];
        return index;
    }
}

int main ()
{
    vector<double> price;
    vector<double> weight;
    price.push_back(1.0);
    price.push_back(2.0);
    price.push_back(3.0);

    weight.push_back(1.0);
    weight.push_back(1.0);
    //weight.push_back(1.0);

    double index = computeIndex(price,weight);
    cout << "Index value = " << index << endl;

    return 0;
}
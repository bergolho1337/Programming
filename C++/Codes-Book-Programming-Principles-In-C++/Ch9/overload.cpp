#include <iostream>

using namespace std;

// Cria uma classe de enumeracao
// Os meses apos Janeiro serao inicializados pelo compilador pegando o valor anterior e incrementando de 1
enum class Month
{
    Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

// Reescrever o operador ++ para a classe Month
// Se o mes atual for Dezembro voltar para Janeiro
Month operator++ (Month &m)
{
    m = (m == Month::Dec) ? Month::Jan : Month(int(m)+1);
    return m;
}

int main ()
{
    Month m = Month::Sep;
    for (int k = 0; k < 5; k++)
    {
        cout << int(m) << endl;
        ++m;
    }
    
}
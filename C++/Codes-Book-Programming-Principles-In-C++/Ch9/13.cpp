#include <iostream>
#include <cmath>

using namespace std;

class Rational
{
private:
    int num;
    int den;
public:
    class Invalid{ };
    Rational (int num, int den);
    double toDouble ();
    int getNum () { return num; }
    int getDen () { return den; }

    // Operator overload (Doing inside the class)
    // You can acess directly the data of a const object in a operator overload 
    Rational operator+ (const Rational &b)
    {
        Rational r(this->num*b.den + b.num*this->den, this->den * b.den);
        return r;
    }

    Rational operator- (const Rational &b)
    {
        Rational r(this->num*b.den - b.num*this->den, this->den * b.den);
        return r;
    }

    Rational operator* (const Rational &b)
    {
        Rational r(this->num*b.num, this->den*b.den);
        return r;
    }

    Rational operator/ (const Rational &b)
    {
        Rational r(this->num*b.den, this->den*b.num);
        return r;
    }

    bool operator== (const Rational &b)
    {
        return (this->num == b.num && this->den == b.den);
    }

    bool operator!= (const Rational &b)
    {
        return (!(this->num == b.num && this->den == b.den));
    }

    /* A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. */
    friend ostream& operator<< (ostream &os, const Rational &a)
    {
        os << a.num << "/" << a.den;
        return os;
    } 
};

Rational::Rational (int num, int den) : num{num}, den{den}
{
    if (den == 0)
    {
        cout << "[-] ERROR ! Denominator is zero !" << endl;
        throw Invalid{};
    }
} 

double Rational::toDouble ()
{
    return (double)num / (double)den;
}

int main ()
{
    Rational r1(2,3);
    Rational r2(1,6);
    Rational r3(2,3);
    //Rational r4(2,0);
    cout << "Addition = " << r1+r2 << endl;
    cout << "Subtraction = " << r1-r2 << endl;
    cout << "Multiplication = " << r1*r2 << endl;
    cout << "Division = " << r1/r2 << endl;
    if (r1 == r2)
        cout << "[+] The Rationals are equal!" << endl;
    else
        cout << "[-] The Rationals are NOT equal!" << endl;
    if (r1 != r3)
        cout << "[-] The Rationals are NOT equal!" << endl;
    else
        cout << "[+] The Rationals are equal!" << endl;

    cout << "To double: " << r1.toDouble() << endl;
    cout << "To double: " << r2.toDouble() << endl;
    cout << "To double: " << r3.toDouble() << endl;

    return 0;
}
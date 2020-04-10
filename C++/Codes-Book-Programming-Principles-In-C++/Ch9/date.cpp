#include <iostream>

using namespace std;

// Months of the year
enum class Month
{
    Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

// Year must be in range [min,max)
class Year
{
    static constexpr int min = 1800;
    static constexpr int max = 2200;
public:
    class Invalid { };                                                      // Class used for exceptions
    Year (int x) : y{x} { if (x < min || x >= max) throw Invalid{}; }       // Constructor
    int year () { return y; }
private:
    int y;
};

class Date
{
public:
    Date (Year y, Month m, int d) : y{y}, m{m}, d{d} {};
    int day () { return d; }
    int month () { return int(m); }
    int year () { return y.year(); }
private:
    Year y;
    Month m;
    int d;
};

ostream& operator<< (ostream &os, Date d)
{
    return os << d.day() << "/" << d.month() << "/" << d.year() << endl;
}

int main ()
{
    Date dx{Year{1993},Month::Mar,30};
    cout << dx;
}
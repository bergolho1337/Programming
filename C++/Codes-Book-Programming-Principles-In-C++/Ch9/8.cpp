#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

class Book;
class Patron;

enum class Genre
{
    fiction=1, nonfiction, periodical, biography, children
};

/* =============================================================================================================== */
class Book
{
private:
    bool check_in;
    Genre genre;
    string isbn;
    string title;
    string author;
    string copyright;
public:
    class Invalid { };
    Book (string isbn, string title, string author, string copyright, Genre genre);
    string getISBN() { return isbn; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getCopyright() { return copyright; }
    int getGenre () { return int(genre); }
    void checkIn ();
    void checkOut ();
};

// Helper functions for class Book
bool is_Integer (string s);
bool is_ISBN (string isbn);

Book::Book (string isbn, string title, string author, string copyright, Genre genre)
    : check_in{true}, genre{genre}, isbn{isbn}, title{title}, author{author}, copyright{copyright}
{
    if (!is_ISBN(isbn))
    {
        cout << "[-] ERROR ! Wrong format of ISBN. Format:> n-n-n-x" << endl;
        cout << "n = Integer" << endl;
        cout << "x = Digit or letter" << endl;
        throw Invalid{};
    }
}

bool operator== (Book &a, Book &b)
{
    return a.getISBN() == b.getISBN();
}

bool operator!= (Book &a, Book &b)
{
    return a.getISBN() != b.getISBN();
}

ostream& operator<< (ostream &os, Book &a)
{
    os << a.getISBN() << endl;
    os << a.getTitle() << endl;
    os << a.getAuthor() << endl;
    switch (a.getGenre())
    {
        case 1: os << "fiction" << endl;
                break;
        case 2: os << "nonfiction" << endl;
                break;
        case 3: os << "periodical" << endl;
                break;
        case 4: os << "biography" << endl;
                break;
        case 5: os << "children" << endl;
                break;
    }
    return os;
}

bool is_Integer (string s)
{
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

bool is_ISBN (string isbn)
{
    if (isbn.find('-') == string::npos)
        return false;
    else
    {
        stringstream ss(isbn);
        string token;
        vector<string> tokens;
        while (getline(ss,token,'-'))
            tokens.push_back(token);

        if (tokens.size() != 4)
            return false;
        else
        {
            for (int i = 0; i < 3; i++)
                if (!is_Integer(tokens[i])) return false;
            if ((int)token.size() != 1 || !isalnum(token[0])) return false;
            return true;
        }
    }
}

/* =============================================================================================================== */

class Patron
{
private:
    string uname;
    string idcard;
    int fee;
public:
    Patron (string uname, string idcard);
    string getUsername () { return uname; }
    string getIdcard () { return idcard; }
    int getFee () { return fee; }
    void setFee (int fee) { this->fee = fee; }
};

// Helper functions for class Patron
bool haveFee (Patron p);

// All new users don't have a fee to pay
Patron::Patron (string uname, string idcard) :
        uname{uname}, idcard{idcard}, fee{0} { }

bool haveFee (Patron p)
{
    return (p.getFee()) ? true : false;
}

ostream& operator<< (ostream &os, Patron p)
{
    os << p.getUsername() << endl;
    os << p.getIdcard() << endl;
    if (haveFee(p)) os << p.getFee() << endl;
    return os;
}

/* =============================================================================================================== */


int main ()
{
    /*
    Book book("22-22-23-Y","C++ Book","Bjarne","2013",Genre::nonfiction);
    Book book2("22-22-22-Y","C++ Book Edition 2","Bjarne","2014",Genre::nonfiction);
    Book book3("11-11-11-X","Peter Pan","Disney","1990",Genre::children);
    
    if (book == book2)
        cout << "The books are equal" << endl;
    else
        cout << "The books are NOT equal" << endl;
    
    if (book != book2)
        cout << "The books are different" << endl;
    else
        cout << "The books are NOT different" << endl;

    cout << book << endl;
    cout << book2 << endl;
    cout << book3 << endl;
    */

    Patron p1("Lucas","123");
    Patron p2("Ricardo","289");
    p2.setFee(100);

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}
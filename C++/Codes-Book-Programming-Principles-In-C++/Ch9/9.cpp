#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

enum class Genre;
enum class Month;
class Year;
class Library;
class Book;
class Patron;
class Date;
struct Transaction;

/* =============================================================================================================== */
/* Class Book */

enum class Genre
{
    fiction=1, nonfiction, periodical, biography, children
};

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
    bool getStatus () { return check_in; }
    void checkIn ();
    void checkOut ();
};

// Helper functions for class Book
bool is_Integer (string s);
bool is_ISBN (string isbn);

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

// Overload operators
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
    os << a.getStatus() << endl;
    return os;
}

// Constructor
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

void Book::checkIn ()
{
    if (!this->check_in)
        this->check_in = true;
    else
        cout << "[!] Book already checked in !" << endl;
}

void Book::checkOut ()
{
    if (this->check_in)
        this->check_in = false;
    else
        cout << "[!] Book already checked out !" << endl;
}

/* =============================================================================================================== */
/* Class Patron */

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

bool haveFee (Patron p)
{
    return (p.getFee()) ? true : false;
}

// Operator overload
ostream& operator<< (ostream &os, Patron p)
{
    os << p.getUsername() << endl;
    os << p.getIdcard() << endl;
    if (haveFee(p)) os << p.getFee() << endl;
    return os;
}

bool operator== (Patron &a, Patron &b)
{
    return a.getUsername() == b.getUsername();
}

bool operator!= (Patron &a, Patron &b)
{
    return a.getUsername() != b.getUsername();
}

// All new users don't have a fee to pay
Patron::Patron (string uname, string idcard) :
        uname{uname}, idcard{idcard}, fee{0} { }

/* =============================================================================================================== */
/* Class Date */

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
/* =============================================================================================================== */
/* Struct Transaction */

struct Transaction
{
    Book book;
    Patron patron;
    Date date;

    Transaction (Book b, Patron p, Date d) : book{b}, patron{p}, date{d} {};
}typedef Transaction;

ostream& operator<< (ostream &os, Transaction t)
{
    os << "==== Transaction ====" << endl;
    os << "Book" << endl;
    os << t.book << endl;
    os << "Patron" << endl;
    os << t.patron << endl;
    os << "Date" << endl;
    os << t.date << endl;
    return os;
}

/* =============================================================================================================== */
/* Class Library */
class Library
{
private:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;
public:
    class Invalid { };
    Library () { };
    void addBook (string isbn, string title, string author, string copyright, Genre genre);
    void addPatron (string uname, string idcard);
    int searchBook (string title);
    int searchPatron (string uname);
    bool addFeeToPatron (string uname, int fee);
    void checkOutBook (string uname, string title, Date d);
    void printBooks ();
    void printPatrons ();
    void printTransactions ();
    void printNoFeePatron ();
    vector<Book> getBooks () { return books; }
    vector<Patron> getPatrons () { return patrons; }
    vector<Transaction> getTransactions () { return transactions; }
};

void Library::addBook (string isbn, string title, string author, string copyright, Genre genre)
{
    Book b(isbn,title,author,copyright,genre);
    this->books.push_back(b);
}

void Library::addPatron (string uname, string idcard)
{
    Patron p(uname,idcard);
    this->patrons.push_back(p);
}

int Library::searchBook (string title)
{
    for (int i = 0; i < (int)this->books.size(); i++)
    {
        if (this->books[i].getTitle() == title)
            return i;
    }
    return -1;
}

int Library::searchPatron (string uname)
{
    for (int i = 0; i < (int)this->patrons.size(); i++)
    {
        if (this->patrons[i].getUsername() == uname)
            return i;
    }
    return -1;
}

bool Library::addFeeToPatron (string uname, int fee)
{
    int index = searchPatron(uname);
    if (index != -1)
    {
        this->patrons[index].setFee(fee);
        return true;
    }
    else
    {
        cout << "[!] Patron " << uname << " not found in the library" << endl;
        return false;
    }
}

void Library::checkOutBook (string uname, string title, Date d)
{
    int iPatron = searchPatron(uname);
    int iBook = searchBook(title);
    if (iBook == -1 || iPatron == -1)
    {
        cout << "[-] ERROR ! Book or patron not found in the library" << endl;
        throw Invalid{};
    }
    else
    {
        if (haveFee(this->patrons[iPatron]))
        {
            cout << "[-] ERROR ! There is a fee related to the patron " << this->patrons[iPatron].getUsername() << endl;
            throw Invalid{};
        }
        else if (this->books[iBook].getStatus() == false)
        {
            cout << "[-] ERROR ! The book " << this->books[iBook].getTitle() << " is checked out already !" << endl;
            throw Invalid{};
        }
        else
        {
            Book b = this->books[iBook];
            Patron p = this->patrons[iPatron];
            Transaction t(b,p,d);
            this->transactions.push_back(t);
            this->books[iBook].checkOut();
        }
    }
}

void printBooks (Library l)
{
    cout << "[!] Printing all books in the library ..." << endl;
    for (Book b : l.getBooks())
        cout << b << endl;
}

void printPatrons (Library l)
{
    cout << "[!] Printing all patrons in the library ..." << endl;
    for (Patron p : l.getPatrons())
        cout << p << endl;
}

void printTransactions (Library l)
{
    cout << "[!] Printing all transactions of the library ..." << endl;
    vector<Transaction> t = l.getTransactions();
    for (int i = 0; i < (int)t.size(); i++)
        cout << t[i] << endl;
}

void printNoFeePatron (Library l)
{
    cout << "[!] Printing all patrons with NO FEE in the library ..." << endl;
    for (Patron p : l.getPatrons())
    {
        if (!haveFee(p))
            cout << p << endl;
    }
}
/* =============================================================================================================== */

int main ()
{
    Library l;
    
    // Adding books
    l.addBook("22-22-23-Y","C++ Book","Bjarne","2013",Genre::nonfiction);
    l.addBook("11-11-11-X","Peter Pan","Disney","1990",Genre::children);
    l.addBook("44-55-66-A","Steve Jobs: Life","Jobs","2010",Genre::biography);
    printBooks(l);

    // Adding patrons
    l.addPatron("Lucas","111");
    l.addPatron("Ricardo","112");
    l.addPatron("Karine","281");
    // Adding fee
    l.addFeeToPatron("Ricardo",100);
    //printPatrons(l);
    //printNoFeePatron(l);    

    l.checkOutBook("Lucas","Peter Pan",{Year{2017},Month::Jun,15});
    l.checkOutBook("Karine","Steve Jobs: Life",{Year{2017},Month::Jun,16});
    printBooks(l);
    printTransactions(l);

    return 0;
}
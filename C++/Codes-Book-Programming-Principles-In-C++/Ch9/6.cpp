#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

class Book
{
private:
    bool check_in;
    string isbn;
    string title;
    string author;
    string copyright;
public:
    class Invalid { };
    Book (string isbn, string title, string author, string copyright);
    string getISBN() { return isbn; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getCopyright() { return copyright; }
    void checkIn ();
    void checkOut ();
};

bool is_Integer (string s);
bool is_ISBN (string isbn);

Book::Book (string isbn, string title, string author, string copyright)
    : check_in{true}, isbn{isbn}, title{title}, author{author}, copyright{copyright}
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

int main ()
{
    Book book("22-22-23-Y","C++ Book","Bjarne","2013");
    Book book2("22-22-22-Y","C++ Book Edition 2","Bjarne","2014");
    
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

    return 0;
}
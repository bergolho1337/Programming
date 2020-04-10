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
    Book book("22-22-A2-Y","C++ Book","Bjarne","2013");
    cout << book.getISBN() << endl;
    cout << book.getTitle() << endl;
    cout << book.getAuthor() << endl;
    cout << book.getCopyright() << endl;
    return 0;
}
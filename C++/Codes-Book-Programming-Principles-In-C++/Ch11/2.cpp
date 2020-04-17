// 2- Write a program that given a file name and a word outputs each line that contains that word together with the line number.

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

bool is_white (char c)
{
    static const string white = ";,.:?!(){}[]<>/&^$@#%*|~";

    for (char w : white)
        if (c == w) return true;
    return false;
}

int main (int argc, char *argv[])
{
    if (argc-1 != 2)
    {
        cout << "Usage:> ./2 <filename> <word>" << endl;
        exit(EXIT_FAILURE);
    }

    string filename(argv[1]);
    string matching_word(argv[2]);

    // Open the file for reading
    ifstream is(filename);
    if (!is)
    {
        cerr << "[-] ERROR! Cannot open filename " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    int counter = 1;
    // Pass through each line of the file
    while (getline(is,line))
    {
        // Put the line into a stringstream
        stringstream ss(line);
        // Read each word from the line
        for (string word; ss >> word; )
        {
            // Eliminate punctuation
            string processed_word;
            for (char &ch : word)
            {
                if (!is_white(ch))
                    processed_word += ch;
            }
            // Compare the 'processed_word' 
            if (processed_word == matching_word)
            {
                cout << "Word '" << matching_word << "' found in line " << counter << endl;
            }
            //cout << processed_word << endl;
        }

        counter++;
    }

    is.close();

    return 0;
}

/*
class Punct_stream {
private:
    istream &source;            // Character source
    istringstream buffer;       // Formatting buffer
    string white;               // Set of characters considered "whitespace"
    bool sensitive;             // Is the stream case sensitive
public:
    Punct_stream (istream &is) : source(is), sensitive(true) {}
    void whitespace (const string &s) { white = s; }
    void add_white (char c) { white += c; }
    bool is_white (char c)
    {
        for (char w : white)
            if (c == w) return true;
        return false;
    }
    void case_sensitive (bool b) { sensitive = b; }
    bool is_case_sensitive () { return sensitive; }

    Punct_stream& operator>> (string &s)
    {
        while (!(buffer >> s))
        {
            if (buffer.bad() || !source.good()) return *this;
            buffer.clear();

            string line;
            getline(source,line);

            for (char &ch : line)
            {
                if (is_white(ch))
                    ch = ' ';
                else if (!sensitive)
                    ch = tolower(ch);
            }

            buffer.str(line);
        }
        return *this;
    }

    operator bool ();
};

Punct_stream::operator bool ()
{
    return !(source.fail() || source.bad()) && buffer.good();
}
*/
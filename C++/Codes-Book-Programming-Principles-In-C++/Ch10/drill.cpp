#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const unsigned int NUM_POINTS = 10;

class Point
{
public:
    // Constructor
    Point () { }
    Point (double x, double y) { this->x = x; this->y = y; }
    // Inline
    double getX () { return this->x; }
    double getY () { return this->y; }
    // Output
    friend ostream& operator<< (ostream &os, const Point &p)
    {
        os << p.x << " " << p.y << endl;
        return os;
    }
    // Input
    friend istream& operator>> (istream &is, Point &p)
    {
        is >> p.x >> p.y;
        return is;
    } 
private:
    double x, y;
};

void writePointsToTxt (const vector<Point> pts)
{
    ofstream out("mydata.txt");
    for (int i = 0; i < (int)pts.size(); i++)
        out << pts[i] << endl;
    out.close();
}

void readPointsFromTxt (vector<Point> &pts)
{
    ifstream in("mydata.txt");
    for (Point p; in >> p;)
        pts.push_back(p);
    in.close();
}

void printPoints (const string label, const vector<Point> pts)
{
    cout << label << endl;
    for (int i = 0; i < (int)pts.size(); i++)
        cout << pts[i] << endl;
}

bool comparePoints (vector<Point> pts, vector<Point> pts_in)
{
    if (pts.size() != pts_in.size()) return false;

    for (int i = 0; i < (int)pts.size(); i++)
    {
        if (pts[i].getX() != pts_in[i].getX() || pts[i].getY() != pts_in[i].getY())
            return false;
    }
    return true;
}

int main ()
{
    vector<Point> pts;
    vector<Point> pts_in;
    for (int i = 0; i < NUM_POINTS; i++)
    {
        Point p; cin >> p;
        pts.push_back(p);
    }
    //writePointsToTxt(pts);
    readPointsFromTxt(pts_in);

    printPoints("Read from cin",pts);
    printPoints("Read from file",pts_in);

    if (!comparePoints(pts,pts_in)) cout << "[-] Something went wrong" << endl;
    else                            cout << "[+] Everything is ok" << endl;

    return 0;
}
// 9. Split the binary I/O: one program that converts an ordinary text file into binary and one program that reads binary and converts to text.
//    Test these programs by comparing a text file with what you get by converting it to binary and back.

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Point 
{
public:
    uint32_t id;
    double x, y, z;
public:
    Point (const uint32_t id, const double x, const double y, const double z)
    {
        this->id = id;
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class Line
{
public:
    uint32_t src;
    uint32_t dest;
public:
    Line (const uint32_t src, const uint32_t dest)
    {
        this->src = src;
        this->dest = dest;
    }   
};

template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}

void read_ascii_file (string filename, vector<Point> &points, vector<Line> &lines)
{   
    // Open the file for normal reading
    ifstream is(filename);
    if (!is)
    {
        cerr << "[-] ERROR! Cannot open filename " << filename << endl;
        exit(EXIT_FAILURE);
    }

    uint32_t np, nl;
    is >> np;
    for (uint32_t i = 0; i < np; i++)
    {
        double pos[3];
        is >> pos[0] >> pos[1] >> pos[2];
        
        Point p(i,pos[0],pos[1],pos[2]);
        points.push_back(p);
    }
    is >> nl;
    for (uint32_t i = 0; i < nl; i++)
    {
        double line[2];
        is >> line[0] >> line[1];
        
        Line l(line[0],line[1]);
        lines.push_back(l);
    }

    is.close();
}

void read_binary_file (string filename, vector<Point> &points, vector<Line> &lines)
{
    // Open the file for binary reading
    ifstream is(filename,ios_base::binary);
    if (!is)
    {
        cerr << "[-] ERROR! Cannot open filename " << filename << endl;
        exit(EXIT_FAILURE);
    }

    uint32_t np, nl;
    is.read(as_bytes(np),sizeof(uint32_t));
    for (uint32_t i = 0; i < np; i++)
    {
        double pos[3];
        is.read(as_bytes(pos),sizeof(double)*3);

        Point p(i,pos[0],pos[1],pos[2]);
        points.push_back(p);
    }
    is.read(as_bytes(nl),sizeof(uint32_t));
    for (uint32_t i = 0; i < nl; i++)
    {
        uint32_t link[2];
        is.read(as_bytes(link),sizeof(uint32_t)*2);
        
        Line l(link[0],link[1]);
        lines.push_back(l);
    }

    is.close();
}

void write_binary_file (vector<Point> points, vector<Line> lines)
{
    string filename = "output_file_9.bin";

    // Open file for binary writing
    ofstream os(filename,ios_base::binary);
    if (!os)
    {
        cerr << "[-] ERROR! Cannot open filename " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Write the points
    uint32_t np = points.size();
    os.write(as_bytes(np),sizeof(uint32_t));
    for (Point p : points)
    {
        double pos[3];
        pos[0] = p.x;
        pos[1] = p.y;
        pos[2] = p.z;

        os.write(as_bytes(pos),sizeof(double)*3);
    }
    
    // Write the lines
    uint32_t nl = lines.size();
    os.write(as_bytes(nl),sizeof(uint32_t));
    for (Line l : lines)
    {
        uint32_t link[2];
        link[0] = l.src;
        link[1] = l.dest;

        os.write(as_bytes(link),sizeof(uint32_t)*2);
    }

    os.close();
}

void write_ascii_file (vector<Point> points, vector<Line> lines)
{
    string filename = "output_file_9.txt";

    // Open file for writing
    ofstream os(filename);
    if (!os)
    {
        cerr << "[-] ERROR! Cannot open filename " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Write the points
    uint32_t np = points.size();
    os << np << endl;
    for (Point p : points)
    {
        double pos[3];
        pos[0] = p.x;
        pos[1] = p.y;
        pos[2] = p.z;

        os << pos[0] << " " << pos[1] << " " << pos[2] << endl;
    }
    
    // Write the lines
    uint32_t nl = lines.size();
    os << nl << endl;
    for (Line l : lines)
    {
        uint32_t link[2];
        link[0] = l.src;
        link[1] = l.dest;

        os << link[0] << " " << link[1] << endl;
    }

    os.close();
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "Usage:> ./9 <filename>" << endl;
        exit(EXIT_FAILURE);
    }

    string filename(argv[1]);

    vector<Point> points;
    vector<Line> lines;

    read_ascii_file(filename,points,lines);
    write_binary_file(points,lines);
    write_ascii_file(points,lines);

    vector<Point> points2;
    vector<Line> lines2;

    filename = "output_file_9.bin";
    read_binary_file(filename,points2,lines2);

    for (uint32_t i = 0; i < points2.size(); i++)
        cout << points2[i].x << " " << points2[i].y << " " << points2[i].z << endl;

    for (uint32_t i = 0; i < lines2.size(); i++)
        cout << lines2[i].src << " " << lines2[i].dest << endl; 


    return 0;
}

// Simple program to test the STL map for building a unique set of Points

#include <iostream>
#include <set>
#include <map>

class Point
{
public:
	uint32_t id;
	double pos[3];
public:
	Point (const uint32_t id, const double x, const double y, const double z)
	{
		this->id = id;
		this->pos[0] = x;
		this->pos[1] = y;
		this->pos[2] = z;
	}
	void print ()
	{
		printf("%u = (%lf %lf %lf)\n",this->id,this->pos[0],this->pos[1],this->pos[2]);
	}
	// To use the map, you must define the operator '<' for the class
	bool operator <(const Point& point) const
    {
        return (this->pos[0] < point.pos[0]) || \
               ((!(point.pos[0] < this->pos[0])) && (this->pos[1] < point.pos[1])) || \
               ((!(point.pos[0] < this->pos[0])) && (!(point.pos[1] < this->pos[1])) && (this->pos[2] < point.pos[2]));
    }
};

int main (int argc, char *argv[])
{
	Point p1(0,1,2,3);
	Point p2(1,4,5,6);
	Point p3(2,7,8,9);
	Point p4(3,1,2,3);
	Point p5(4,4,5,6);
	Point p6(5,7,8,9);

	std::pair<std::set<Point>::iterator,bool> ret;
	std::set<Point> unique_points;
	ret = unique_points.insert( p1 );
	if (ret.second) printf("SUCESS!\n"); else printf("FAIL!\n"); 
	ret = unique_points.insert( p2 );
	if (ret.second) printf("SUCESS!\n"); else printf("FAIL!\n");
	ret = unique_points.insert( p3 );
	if (ret.second) printf("SUCESS!\n"); else printf("FAIL!\n");
	ret = unique_points.insert( p4 );
	if (ret.second) printf("SUCESS!\n"); else printf("FAIL!\n");
	ret = unique_points.insert( p5 );
	if (ret.second) printf("SUCESS!\n"); else printf("FAIL!\n");
	ret = unique_points.insert( p6 );
	if (ret.second) printf("SUCESS!\n"); else printf("FAIL!\n");

	for (auto it = unique_points.begin(); it != unique_points.end(); ++it)
	{
		printf("Id = %u --> (%lf, %lf, %lf)\n",it->id,it->pos[0],it->pos[1],it->pos[2]);
	}

	return 0;
}

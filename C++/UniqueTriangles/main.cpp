// Simple program to test the STL map for building a unique set of Triangles

#include <iostream>
#include <set>
#include <map>

class Triangle
{
public:
	int v0;
	int v1;
	int v2;
public:
	Triangle (const int v0, const int v1, const int v2)
	{
		this->v0 = v0;
		this->v1 = v1;
		this->v2 = v2;
	}
	void print ()
	{
		printf("[%d %d %d]\n",this->v0,this->v1,this->v2);
	}
	// To use the map, you must define the operator '<' for the class
	bool operator <(const Triangle& tri) const
    {
        return (this->v0 < tri.v0) || \
               ((!(tri.v0 < this->v0)) && (this->v1 < tri.v1)) || \
               ((!(tri.v0 < this->v0)) && (!(tri.v1 < this->v1)) && (this->v2 < tri.v2));
    }
};

int main (int argc, char *argv[])
{
	Triangle t1(1,2,3);
	Triangle t2(4,5,6);
	Triangle t3(7,8,9);
	Triangle t4(1,2,3);
	Triangle t5(4,5,6);
	Triangle t6(7,8,9);

	std::pair<std::map<Triangle,int>::iterator,bool> ret;
	std::map<Triangle,int> unique_triangles;
	ret = unique_triangles.insert( std::pair<Triangle,int>(t1,1) );
	(ret.second) ? printf("[+] SUCESS!\n") : printf("[-] FAIL!\n");
	ret = unique_triangles.insert( std::pair<Triangle,int>(t2,2) );
	(ret.second) ? printf("[+] SUCESS!\n") : printf("[-] FAIL!\n");
	ret = unique_triangles.insert( std::pair<Triangle,int>(t3,3) );
	(ret.second) ? printf("[+] SUCESS!\n") : printf("[-] FAIL!\n");
	ret = unique_triangles.insert( std::pair<Triangle,int>(t4,4) );
	(ret.second) ? printf("[+] SUCESS!\n") : printf("[-] FAIL!\n");
	ret = unique_triangles.insert( std::pair<Triangle,int>(t5,5) );
	(ret.second) ? printf("[+] SUCESS!\n") : printf("[-] FAIL!\n");
	ret = unique_triangles.insert( std::pair<Triangle,int>(t6,6) );
	(ret.second) ? printf("[+] SUCESS!\n") : printf("[-] FAIL!\n");

	for (auto it = unique_triangles.begin(); it != unique_triangles.end(); ++it)
	{
		printf("[key,value] = [{%d,%d,%d},%d]\n",it->first.v0,it->first.v1,it->first.v2,it->second);
	}

	return 0;
}

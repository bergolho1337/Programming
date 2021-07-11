#include "dbm/dbm.h"

int main (int argc, char *argv[])
{
	const uint32_t N = 200;
	const uint32_t MAX_ITER = 2000;
	const double H = 2.0;
	const double ETA = 12.0;

	DBM *dbm = new DBM(N,MAX_ITER,H,ETA);

	dbm->set_root((N/2),(N/2),(N/2));
	dbm->set_neighbours();
	//dbm->print();

	dbm->run();

	delete dbm;

	return 0;
}

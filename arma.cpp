#define ARMA_HAVE_STD_TR1
#include <armadillo>
#include <iostream>
using namespace std;
using namespace arma;

int
main ()
{
	vec a = randu<vec>(4);
	vec b = randu<vec>(4);

		running_stat_vec<vec::elem_type> stats(true);

	stats (a);
	stats (b);

	cout << stats.cov() << endl;

	return 0;
}

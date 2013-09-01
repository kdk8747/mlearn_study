#pragma once
#include <vector>
#include <string>
#include <armadillo>
using namespace arma;
using namespace std;

class Data {

public:
	vec feature;
	string type;

	Data (double f1, double f2, double f3, double f4, string t): type (t) {
		feature << f1 << f2 << f3 << f4;
	}
};

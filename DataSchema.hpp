#pragma once
#include <vector>
#include <set>
#include <string>
using namespace std;

class DataSchema {
public:
	vector<string> featureName;
	set<string> validTypes;

	DataSchema () {
	}
};

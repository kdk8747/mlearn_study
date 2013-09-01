#pragma once
#include <vector>
#include "Data.hpp"
#include "DataSchema.hpp"
using namespace std;

class DataSet {

protected:
	DataSchema dataSchema;

public:
	vector<Data> entry;

	DataSet () {
	}

	vector<DataSet*> partition (int k) {
		return vector<DataSet*> ();
	}

	DataSet merge (DataSet *ds) {
		return DataSet ();
	}
};

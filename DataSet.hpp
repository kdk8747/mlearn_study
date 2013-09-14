#pragma once
#include <vector>
#include <map>
#include <cassert>
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

	DataSet (DataSchema ds): dataSchema (ds){
	}

	vector<DataSet*> partition (int k) const {
		assert (k >= 2);
		map<string, int> count;
		for (const Data &d : entry) {
			count[d.type] ++;
		}

		vector<DataSet*> ret;
		for (int i = 0; i < k; i ++)
			ret.push_back (new DataSet (dataSchema));

		for (const pair<string, int> it : count) {
			string type = it.first;
			int count = it.second;
			int unit = (count + k - 1) / k;
			for (int i = 0, j = 0; i < (int)entry.size (); i ++)
					if (type == entry[i].type){
						ret[j/unit]->entry.push_back (entry[i]);
						j ++;
					}
		}
		return ret;
	}
};

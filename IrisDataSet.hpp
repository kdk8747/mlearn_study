#pragma once
#include <cstdio>
#include <cstring>
#include "DataSchema.hpp"
using namespace std;


class IrisDataSet : public DataSet{
public:

	IrisDataSet () : DataSet (){
		initDataSchema ();
		FILE *in = fopen ("iris.data", "r");

		double d[4];
		char type[32];
		while (fscanf (in, "%lf,%lf,%lf,%lf,%s", &d[0], &d[1], &d[2], &d[3], type) != EOF){
			entry.push_back (Data (d[0],d[1],d[2],d[3],type));
		}
	}


	void initDataSchema () {
		dataSchema.validTypes.insert ("Iris-setosa");
		dataSchema.validTypes.insert ("Iris-versicolor");
		dataSchema.validTypes.insert ("Iris-virginica");
		dataSchema.featureName.push_back ("sepalLength");
		dataSchema.featureName.push_back ("sepalWidth");
		dataSchema.featureName.push_back ("petalLength");
		dataSchema.featureName.push_back ("petalWidth");
	}


private:
};

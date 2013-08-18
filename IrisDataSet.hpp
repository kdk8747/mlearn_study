#pragma once
#include <cstdio>
#include <cstring>
#include "../my_library/matrix/SquareMatrix.hpp"
using namespace std;

typedef vector<double> IrisData;
static const int dimension = 4;
static const char *dimensionName[dimension] = {
	"sepalLength",
	"sepalWidth",
	"petalLength",
	"petalWidth"
};


class IrisDataSet {
public:

	IrisDataSet (const char *testDataPath) {
		FILE *in = fopen (testDataPath, "r");

		IrisData d (dimension, 0.0);
		char type[32];
		while (fscanf (in, "%lf,%lf,%lf,%lf,%s", &d[0], &d[1], &d[2], &d[3], type) != EOF){
			if (0 == strcmp (type, "Iris-setosa"))
				if (setosa.size () < 25){
					setosa.push_back (d);
					continue;
				}
			if (0 == strcmp (type, "Iris-versicolor"))
				if (versicolor.size () < 25){
					versicolor.push_back (d);
					continue;
				}
			if (0 == strcmp (type, "Iris-virginica"))
				if (virginica.size () < 25){
					virginica.push_back (d);
					continue;
				}
			test.push_back (make_pair (d, string (type)));
		}
	}



	vector<double> getSetosaAverage () {
		return getEntryAverage (setosa);
	}



	SquareMatrix getSetosaCovarianceMatrix () {
		return getEntryCovarianceMatrix (setosa);
	}



	vector<double> getVersicolorAverage () {
		return getEntryAverage (versicolor);
	}



	SquareMatrix getVersicolorCovarianceMatrix () {
		return getEntryCovarianceMatrix (versicolor);
	}



	vector<double> getVirginicaAverage () {
		return getEntryAverage (virginica);
	}



	SquareMatrix getVirginicaCovarianceMatrix () {
		return getEntryCovarianceMatrix (virginica);
	}



private:

	vector<IrisData> setosa;
	vector<IrisData> versicolor;
	vector<IrisData> virginica;
	vector<pair<IrisData,string> > test;



	vector<double> getEntryAverage (const vector<IrisData> &entry) const {
		vector<double> avg (dimension, 0.0);
		int sz = entry.size ();
		for (int i = 0; i < sz; i ++)
			for (int j = 0; j < dimension; j ++)
				avg[j] += entry[i][j];

		sz = avg.size ();
		for (int i = 0; i < sz; i ++)
			avg[i] /= entry.size ();
		return avg;
	}


	SquareMatrix getEntryCovarianceMatrix (const vector<IrisData> &entry) const {
		SquareMatrix cov (dimension);
		vector<double> avg = getEntryAverage (entry);
		int sz = entry.size ();
		for (int k = 0; k < sz; k ++)
			for (int i = 0; i < dimension; i ++)
				for (int j = 0; j < dimension; j ++)
					cov.entry (i,j) += (entry[k][i] - avg[i]) * (entry[k][j] - avg[j]);

		for (int i = 0; i < dimension; i ++)
			for (int j = 0; j < dimension; j ++)
				cov.entry (i,j) /= sz;
		return cov;
	}
};

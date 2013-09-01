#pragma once
#include "Classifier.hpp"
#include <armadillo>
#include <iostream>
#include <map>
#include <algorithm>
using namespace arma;
using namespace std;

class BayesianClassifier : public Classifier {

	class Distribution {
	public:
		int count;
		running_stat_vec<vec::elem_type> stats;

		Distribution (): count (0), stats (true) {}

		void addSample (const vec &sample) {
			stats (sample);
			count ++;
		}

		mat cov () const {
			running_stat_vec<vec::elem_type> temp = stats;
			return temp.cov ();
		}

		vec mean () const {
			return stats.mean ();
		}
	};

	int count;
	map<string,Distribution> distributionOfType;

public:

	BayesianClassifier (): count (0) {
	}


	void doTraining (const DataSet *ds) {
		for (const Data& d : ds->entry){
			distributionOfType[d.type].addSample (d.feature);
		}
	}



	bool isCorrectlyClassify (const Data *d) const {
		string maxArg;
		double maxVal = 0;
		for (const pair<string,Distribution> &it : distributionOfType){
			string arg = it.first;
			mat cov = it.second.cov ();
			mat invcov = inv (cov);
			vec avg = it.second.mean ();
			double p = (double)it.second.count / count;
			mat val = (invcov * avg).t () * d->feature + (log (p) - avg.t () * invcov * avg);
			if (maxVal < val[0]){
				maxVal = val[0];
				maxArg = arg;
			}
		}
		return maxArg == d->type;
	}



	void printInfo () const {
		cout << "printInfo" << endl;
		for (const pair<string,Distribution> &it : distributionOfType){
			cout << it.first << endl;
			cout << it.second.mean () << endl;
			cout << it.second.cov () << endl << endl;
		}
	}
};

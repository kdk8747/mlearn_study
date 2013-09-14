#pragma once
#include "Classifier.hpp"
#include <armadillo>
#include <iostream>
#include <map>
#include <cfloat>
#include <cmath>
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


	void clear () {
		count = 0;
		distributionOfType.clear ();
	}



	void doTraining (const DataSet *ds) {
		for (const Data& d : ds->entry){
			count ++;
			distributionOfType[d.type].addSample (d.feature);
		}
	}



	bool isCorrectlyClassify (const Data *d) const {
		string maxArg;
		double maxVal = -DBL_MAX;
		double PI = acos (-1);
		vec x = d->feature;

		for (const pair<string,Distribution> &it : distributionOfType){
			const string &arg = it.first;
			const Distribution &d = it.second;
			mat cov = d.cov ();
			mat invcov = inv (cov);
			vec avg = d.mean ();
			double p = (double)d.count / count;

			mat val = (x.t () * invcov * x  -  2 * avg.t () * invcov * x + avg.t () * invcov * avg) / -2.0;
			val = val - x.n_elem * log (2.0 * PI) / 2.0 - log (det (cov)) / 2.0 + log (p);
			if (maxVal < val[0]){
				maxVal = val[0];
				maxArg = arg;
			}
			cout.precision (4);
			cout << fixed << arg << "=" << exp (val[0]) << " ";
		}
		cout << endl;
		if (maxArg != d->type){
			cout << "Expect : " << d->type << ", Actual : " << maxArg << endl << endl;
		}
		return maxArg == d->type;
	}



	void printInfo () const {
		cout << "printInfo" << endl;
		for (const pair<string,Distribution> &it : distributionOfType){
			cout << it.first << endl;
			cout << it.second.mean () << endl;
			cout << it.second.cov () << endl;
			cout << inv (it.second.cov ()) << endl << endl;
		}
	}
};

#pragma once
#include <cassert>
#include <vector>
#include "Classifier.hpp"
#include "DataSet.hpp"
using namespace std;


class Validator {
	DataSet *dataSet;

public:
	Validator (DataSet *ds): dataSet (ds) {
	}
	
	void kFoldValidate (size_t k, Classifier *c) const {
		assert (k >= 2);
		vector<DataSet*> ds = dataSet->partition (k);
		long long totalMisclassifyingCnt = 0;
		long long totalClassifyingTrial = dataSet->entry.size ();

		for (size_t i = 0; i < k; i ++){
			DataSet testSet = *ds[i];
			DataSet trainingSet;
			for (size_t j = 0; j < k; j ++)
				if (i != j)
					trainingSet.merge (ds[j]);
			c->doTraining (&trainingSet);

			for (size_t j = 0; j < testSet.entry.size (); j ++)
				if (! c->isCorrectlyClassify (&testSet.entry[j]))
					totalMisclassifyingCnt ++;
		}

		c->printInfo ();
		double misclassifyingRate = totalMisclassifyingCnt / totalClassifyingTrial;
		cout << "misclassifying rate : " << misclassifyingRate << endl;
	}
};

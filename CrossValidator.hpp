#pragma once

class CrossValidator {
	DataSet *ds;

public:
	CrossValidator (DataSet *ds) DataSet (ds) {
	}

	// 2-fold cross validate
	void validateAndPrintResult (Classifier *c) {
		pair<DataSet, DataSet> t = partition (ds);
		DataSet train = t.first;
		DataSet test  = t.second;

		for (int i = 0; i < ds->numOfClasses (); i ++){
			cout << "Average : " << endl << ds->getAverageOfClass (i) << endl;
			cout << "Covariance Matrix : " << endl << ds->getCovarianceMatrixOfClass (i) << endl;
			for (int j = 0; j < test.size (); j ++)
				c.classify (test[j]);
		}
	}
};

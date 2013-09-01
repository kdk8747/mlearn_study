#include "BayesianClassifier.hpp"
#include "IrisDataSet.hpp"
#include "Validator.hpp"
#include "gtest/gtest.h"

namespace {

class BayesianClassifierTest : public ::testing::Test{

	protected:
		BayesianClassifierTest(){
		}
		virtual ~BayesianClassifierTest () {
		}
		virtual void SetUp () {
		}
		virtual void TearDown () {
		}
};

TEST (BayesianClassifierTest, IrisDataSet) {

	IrisDataSet ds;
	BayesianClassifier b;
	b.doTraining ((DataSet*)&ds);
	b.printInfo ();
	/*
	DataSet *ds = new IrisDataSet ();
	Classifier *c = new BayesianClassifier ();
	Validator v (ds);
	v.kFoldValidate (2,c);
	delete ds;
	delete c;
	*/
	//EXPECT_TRUE ();
}

}


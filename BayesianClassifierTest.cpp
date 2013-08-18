#include "BayesianClassifier.hpp"
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

TEST (BayesianClassifierTest, Inverse) {

	IrisDataSet ds ("iris.data");
	BayesianClassifier bc;

	CrossValidator cv (&ds);
	cv.validateAndPrintResult (&bc);
	
	//EXPECT_TRUE ();
}

}


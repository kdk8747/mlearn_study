#include "IrisDataSet.hpp"
#include "gtest/gtest.h"

namespace {

class IrisDataSetTest : public ::testing::Test{

	protected:
		IrisDataSetTest(){
		}
		virtual ~IrisDataSetTest () {
		}
		virtual void SetUp () {
		}
		virtual void TearDown () {
		}
};

TEST (IrisDataSetTest, Inverse) {

	IrisDataSet ds ("iris.data");
	IrisData setosaAvg = ds.getSetosaAverage ();
	IrisData versicolorAvg = ds.getVersicolorAverage ();
	IrisData virginicaAvg = ds.getVirginicaAverage ();
	for (int i = 0; i < (int)setosaAvg.size (); i ++)
		cout << setosaAvg[i] << " ";
	cout << endl;
	cout << ds.getSetosaCovarianceMatrix () << endl;
	for (int i = 0; i < (int)setosaAvg.size (); i ++)
		cout << versicolorAvg[i] << " ";
	cout << endl;
	cout << ds.getVersicolorCovarianceMatrix () << endl;
	for (int i = 0; i < (int)setosaAvg.size (); i ++)
		cout << virginicaAvg[i] << " ";
	cout << endl;
	cout << ds.getVirginicaCovarianceMatrix () << endl;
	
	//EXPECT_TRUE ();
}

}


#pragma once
#include "DataSet.hpp"

class Classifier {
public:
	virtual void doTraining (const DataSet *ds) = 0;
	virtual bool isCorrectlyClassify (const Data *d) const  = 0;
	virtual void printInfo () const = 0;
};

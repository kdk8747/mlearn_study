runtest: TestMain.cpp IrisDataSetTest.cpp IrisDataSet.hpp
	g++ -Wall -o runtest TestMain.cpp IrisDataSetTest.cpp -lgtest -lpthread

test:
	-rm runtest
	g++ -Wall -o runtest TestMain.cpp IrisDataSetTest.cpp -lgtest -lpthread
	./runtest
clean:
	rm runtest

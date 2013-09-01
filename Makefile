

runtest: TestMain.cpp BayesianClassifierTest.cpp
	g++ -std=c++11 -Wall -o runtest TestMain.cpp BayesianClassifierTest.cpp -lgtest -lpthread -larmadillo

test:
	-rm runtest
	g++ -std=c++11 -Wall -o runtest TestMain.cpp BayesianClassifierTest.cpp -lgtest -lpthread -larmadillo
	./runtest
clean:
	rm runtest

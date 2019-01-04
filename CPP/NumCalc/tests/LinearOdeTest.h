/*
 * LinearOdeTest.h
 *
 *  Created on: 03 Jan 2019
 *      Author: Edward
 */

#ifndef LINEARODETEST_H_
#define LINEARODETEST_H_

class LinearOdeTest {
public:
	bool execute();
private:
	bool testSingleIteration_NoZeros();
	bool testIterateTillTime_N0Zeros();
	bool testFactorial();
	bool testMatPow();
};

#endif /* LINEARODETEST_H_ */

/*
 * LinearOdeTest.cpp
 *
 *  Created on: 03 Jan 2019
 *      Author: Edward
 */
#include <iostream>
#include "LinearOdeTest.h"
#include "../LinearOde.h"
#include <cmath>

//#define debugMat(name, M) cout<<"LinearOdeTest::ln "<<__LINE__<<"::"<<name<<":"<<endl<<M<<endl;
#define debugMat(name, M)
#define LinearOdeTestLogTestResult(result, name) if(result) cout<<"LinearOdeTest::"<< __func__<<"::"<<name<<" passed"<<endl; else cout<<name<<" failed"<<endl;
using namespace std;

bool LinearOdeTest::execute(){
	bool passed = true;
	bool currentTestResult = testFactorial();
	passed = currentTestResult && passed;
	LinearOdeTestLogTestResult(currentTestResult, "testFactorial()");
	currentTestResult = testSingleIteration_NoZeros();
	LinearOdeTestLogTestResult(currentTestResult, "testSingleIteration_NoZeros()");
	passed = currentTestResult && passed;
	currentTestResult = testIterateTillTime_N0Zeros();
	LinearOdeTestLogTestResult(currentTestResult, "testIterateTillTime_N0Zeros()");
	passed = currentTestResult && passed;
	currentTestResult = testMatPow();
	LinearOdeTestLogTestResult(currentTestResult, "testMatPow()");
	passed = currentTestResult && passed;
	return passed;
}

bool LinearOdeTest::testSingleIteration_NoZeros()
{
	LinearOde linearOde;
	mat A;
	A<<1<<2<<endr
	 <<3<<4<<endr;
	mat B;
	B<<1<<endr
	 <<2<<endr;
	SingleResultHolder init;
	mat initState;
	initState<<1<<endr
			 <<2<<endr;
	debugMat("A",A);
	debugMat("B",B);
	debugMat("initState",initState);
	init.setState(initState);
	init.setT(0);
	SingleResultHolder result = linearOde.singleIteration(init, A, B, 0.1, 1);
	debugMat("result.getState()",result.getState());
	mat expected;
	expected<<1.6<<endr
			<<3.3<<endr;
	debugMat("expected",expected);
	return (approx_equal(result.getState(), expected, "absdiff", 0.000001)) && (result.getT() == 0.1);
}

bool LinearOdeTest::testIterateTillTime_N0Zeros()
{
	LinearOde linearOde;
	mat A;
	A<<1<<2<<endr
	 <<3<<4<<endr;
	mat B;
	B<<1<<endr
	 <<2<<endr;
	SingleResultHolder init;
	mat initState;
	initState<<1<<endr
			 <<2<<endr;
	debugMat("A",A);
	debugMat("B",B);
	debugMat("initState",initState);
	init.setState(initState);
	init.setT(0);
	vector<SingleResultHolder> result = linearOde.iterateTillTime(init, A, B, 0.1, 1, 1);
	SingleResultHolder lastDataPoint = result[result.size()-1];
	bool timeTest = lastDataPoint.getT() == 1;
	LinearOdeTestLogTestResult(timeTest,"timeTest");
	mat expected;
	expected<<81.663<<endr
			<<178.241<<endr;
	bool valTest = approx_equal(round(lastDataPoint.getState()*1000)/1000, expected, "absdiff", 0.0001);
	LinearOdeTestLogTestResult(valTest,"valTest");
	return timeTest && valTest;
}

bool LinearOdeTest::testFactorial(){
	LinearOde linearOde;
	bool passed = true;
	int result = linearOde.factorial(1);
	passed = (result==1) && passed;
	LinearOdeTestLogTestResult(result==1,"linearOde.factorial(1)");
	result = linearOde.factorial(2);
	passed = (result==2) && passed;
	LinearOdeTestLogTestResult(result==2,"linearOde.factorial(2)");
	result = linearOde.factorial(3);
	passed = (result==6) && passed;
	LinearOdeTestLogTestResult(result==6,"linearOde.factorial(3)");
	return passed;
}

bool LinearOdeTest::testMatPow(){
	LinearOde linearOde;
	bool passed = true;
	mat A;
	A<<1<<2<<endr
	 <<3<<4<<endr;
	mat result = linearOde.matPow(A,0);
	passed = passed && (approx_equal(result, eye(size(A)), "absdiff", 0.000001));
	LinearOdeTestLogTestResult(passed,"testMatPow()");
	result = linearOde.matPow(A,1);
	passed = passed && (approx_equal(result, A, "absdiff", 0.000001));
	LinearOdeTestLogTestResult(passed,"testMatPow()");
	result = linearOde.matPow(A,2);
	mat expected;
	expected<<7<<10<<endr
			<<15<<22<<endr;
	passed = passed && (approx_equal(result, expected, "absdiff", 0.000001));
	LinearOdeTestLogTestResult(passed,"testMatPow()");
	expected.clear();
	expected<<37<<54<<endr
		    <<81<<118<<endr;
	result = linearOde.matPow(A,3);
	passed = passed && (approx_equal(result, expected, "absdiff", 0.000001));
	LinearOdeTestLogTestResult(passed,"testMatPow()");

	expected<<5.5<<-2.5<<endr
			<<-3.75<<1.75<<endr;
	result = linearOde.matPow(A,-2);
	passed = passed && (approx_equal(result, expected, "absdiff", 0.000001));
	LinearOdeTestLogTestResult(passed,"testMatPow()");
	return passed;
}

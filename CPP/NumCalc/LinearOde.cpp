#include <cmath>
#include <armadillo>
#include <iostream>

#include "LinearOde.h"

#define LINEAR_ODE_DEBUG
#ifndef LINEAR_ODE_DEBUG
#define linearDebugMat(name, M)
#else
//#define linearDebugMat(name, M) cout<<"LinearOde"<<"::ln "<<__LINE__<<"::"<<name<<":"<<endl<<M<<endl;
#define linearDebugMat(name, M)
#endif

using namespace arma;
using namespace std;

LinearOde::LinearOde()
{
}


LinearOde::~LinearOde()
{
}

SingleResultHolder LinearOde::singleIteration(SingleResultHolder initCondition, mat A, mat B, double deltaT, int taylorOrder)
{
	SingleResultHolder result = SingleResultHolder();
	
	mat nextVal = initCondition.getState();
	linearDebugMat("A",A);
	linearDebugMat("B",B);
	linearDebugMat("initCondition.getState()",initCondition.getState())
	for (int n = 1; n <= taylorOrder; n++)
	{
		nextVal = nextVal + (matPow(A,n)*initCondition.getState() + matPow(A,(n - 1))*B)*(pow(deltaT,n)) / factorial(n);
	}
	result.setState(nextVal);
	result.setT(initCondition.getT()+deltaT);
	return result;
}

vector<SingleResultHolder> LinearOde::iterateTillTime(SingleResultHolder initCondition, mat A, mat B, double deltaT, double maxTime, int taylorOrder)
{
	vector<SingleResultHolder> result;
	SingleResultHolder current = initCondition;
	result.push_back(current);
	while (round(current.getT()/deltaT) < maxTime/deltaT){//deal with some precision issues
		current = singleIteration(current, A, B, deltaT, taylorOrder);
		current.setT(round(current.getT()/deltaT)*deltaT);//deal with some precision issues
		result.push_back(current);
	};
	return result;
}

int LinearOde::factorial(const int num) //I should only need this here
{
	if (num <= 1) {
		return 1;
	}
	else {
		return num * factorial(num - 1);
	}
}

mat LinearOde::matPow(const mat& A, const int num)
{
	mat A_;
	int num_ = num;
	if(num < 0)
	{
		A_=inv(A);
		num_ = -num;
	} else {
		A_=A;
	}
	if(num == 0)
	{
		return eye(size(A));
	}
	return A_*matPow(A_,num_-1);
}


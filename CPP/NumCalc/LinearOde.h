#ifndef LINEAR_ODE_H_
#define LINEAR_ODE_H_

#include <vector>
#include <armadillo>

#include "SingleResultHolder.h"

using namespace arma;
using namespace std;
class LinearOde
{
public:
	LinearOde();
	~LinearOde();
	SingleResultHolder singleIteration(SingleResultHolder initCondition, mat A, mat B, double deltaT, int taylorOrder);

	vector<SingleResultHolder> iterateTillTime(SingleResultHolder initCondition, mat A, mat B, double deltaT, double maxTime, int taylorOrder);

	int factorial(const int num);
	mat matPow(const mat& A, const int num); //Armadillo only provides element wise matrix power, so I need to do my own
};

#endif

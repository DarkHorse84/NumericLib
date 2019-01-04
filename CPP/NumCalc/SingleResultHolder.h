#ifndef SINGLE_RESULT_HOLDER_H_
#define SINGLE_RESULT_HOLDER_H_

#include <armadillo>
using namespace arma;

class SingleResultHolder
{
private:
	mat state;
	double t;
public:
	SingleResultHolder();
	~SingleResultHolder();
	mat getState();
	void setState(mat state);
	double getT();
	void setT(double t);
};

#endif

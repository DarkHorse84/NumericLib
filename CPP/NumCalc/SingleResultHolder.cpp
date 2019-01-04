#include "SingleResultHolder.h"


SingleResultHolder::SingleResultHolder()
{
}


SingleResultHolder::~SingleResultHolder()
{
}

mat SingleResultHolder::getState()
{
	return this->state;
}

void SingleResultHolder::setState(mat pState)
{
	this->state = pState;
}

double SingleResultHolder::getT()
{
	return t;
}

void SingleResultHolder::setT(double pT)
{
	this->t = pT;
}

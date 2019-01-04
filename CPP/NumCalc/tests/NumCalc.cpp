#include <iostream>
#include "LinearOdeTest.h"

using namespace std;

int main() {
	LinearOdeTest linearOdeTest;
	if(linearOdeTest.execute())
	{
		cout<<"LinearOdeTest passed"<<endl;
	} else {
		cout<<"LinearOdeTest failed"<<endl;
	}

}

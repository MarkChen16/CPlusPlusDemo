#include "StdAfx.h"
#include "LifeCycle.h"


CT::CT(int i)
{
	mi = i;

	cout<<mi<<":Construct()"<<endl;
}


CT::~CT(void)
{
	cout<<mi<<":Destruct()"<<endl;
}

#include "StdAfx.h"
#include "TaurusJettaCar.h"


//初始化列表也要调用基类的构造函数
TaurusJettaCar::TaurusJettaCar(void):FordCar(), VolkswageCar(), Car("TaurusJetta")
{
}


TaurusJettaCar::~TaurusJettaCar(void)
{
}

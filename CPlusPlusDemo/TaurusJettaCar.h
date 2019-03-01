#pragma once
#include "FordCar.h"
#include "VolkswageCar.h"

//菱形继承的问题: 第二层的FordCar和VolkswageCar基类使用virtual继承
class TaurusJettaCar:public FordCar, public VolkswageCar
{
public:
	TaurusJettaCar(void);
	~TaurusJettaCar(void);
};


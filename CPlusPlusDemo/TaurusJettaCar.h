#pragma once
#include "FordCar.h"
#include "VolkswageCar.h"

//���μ̳е�����: �ڶ����FordCar��VolkswageCar����ʹ��virtual�̳�
class TaurusJettaCar:public FordCar, public VolkswageCar
{
public:
	TaurusJettaCar(void);
	~TaurusJettaCar(void);
};


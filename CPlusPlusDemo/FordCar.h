#pragma once
#include "Car.h"

#include <ctime>

class FordCar : public virtual Car
{
public:
	FordCar(void);
	virtual ~FordCar(void);

	//���ǻ���ĺ���
	void Show() const;
private:
	time_t mCreateTime;
};


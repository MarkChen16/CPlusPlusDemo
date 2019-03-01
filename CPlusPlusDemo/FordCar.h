#pragma once
#include "Car.h"

#include <ctime>

class FordCar : public virtual Car
{
public:
	FordCar(void);
	virtual ~FordCar(void);

	//覆盖基类的函数
	void Show() const;
private:
	time_t mCreateTime;
};


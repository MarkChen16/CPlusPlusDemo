#pragma once
#include "Car.h"
#include "FordCar.h"
#include "VolkswageCar.h"

//定义函数指针类型
typedef void (*BuyCarEventHandler)(const char *szName, const Car& c);
typedef void (*SellCarEventHandler)(const char *szName, const Car& c);

//复合类
class Customer
{
public:
	Customer(const char* szName);
	~Customer(void);

	bool BuyCar(Car *pCar);

	void SellCar(int iPos);

	void ClearCar();

	const char * GetName();

	//买车事件
	BuyCarEventHandler BuyCarEvent;

	//卖车事件
	SellCarEventHandler SellCarEvent;

private:
	char mName[100];
	Car *mCars[10];		//成员类对象最好使用指针，可以避免造成循环定义
};


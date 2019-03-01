#pragma once
#include "Car.h"
#include "FordCar.h"
#include "VolkswageCar.h"

//���庯��ָ������
typedef void (*BuyCarEventHandler)(const char *szName, const Car& c);
typedef void (*SellCarEventHandler)(const char *szName, const Car& c);

//������
class Customer
{
public:
	Customer(const char* szName);
	~Customer(void);

	bool BuyCar(Car *pCar);

	void SellCar(int iPos);

	void ClearCar();

	const char * GetName();

	//���¼�
	BuyCarEventHandler BuyCarEvent;

	//�����¼�
	SellCarEventHandler SellCarEvent;

private:
	char mName[100];
	Car *mCars[10];		//��Ա��������ʹ��ָ�룬���Ա������ѭ������
};


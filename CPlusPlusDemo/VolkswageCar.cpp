#include "StdAfx.h"
#include "VolkswageCar.h"

int VolkswageCar::CREATEYEAR = 1883;

VolkswageCar::VolkswageCar(void):	//���������ࡢ��Ա�����������ڳ�ʼ���б��г�ʼ��
	BRANDNAME("Volkswage Jetta"), Car("Volkswage Jetta", S1, "White", 105), mPrice(108660)
{

}

VolkswageCar::~VolkswageCar(void)
{

}

void VolkswageCar::Run(int mMile)
{
	mMileage = mMileage + mMile;
	mOilCount -= mMile*6;
}

void VolkswageCar::Show() const
{
	Car::Show();	//���û����Show����

	cout<<"Price: "<<this->mPrice<<endl;
}
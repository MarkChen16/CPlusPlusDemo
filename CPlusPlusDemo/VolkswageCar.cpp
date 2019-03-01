#include "StdAfx.h"
#include "VolkswageCar.h"

int VolkswageCar::CREATEYEAR = 1883;

VolkswageCar::VolkswageCar(void):	//常量、基类、成员变量都可以在初始化列表中初始化
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
	Car::Show();	//调用基类的Show函数

	cout<<"Price: "<<this->mPrice<<endl;
}
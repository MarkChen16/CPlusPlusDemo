#include "StdAfx.h"
#include "Car.h"

#include "Customer.h"

//���ξ���
#pragma warning(disable:4996 4578)

using namespace GlobalSpace;

void SetGlobalCarCount(long lValue)
{
	GlobalCarCount = lValue;
}

Car& operator >>(Car & myCar, int mMile)
{
	myCar.Run(mMile);
	return myCar;
}

Car::Car(const char* brandName, CardType ct, const char *colorName, 
		int power, int seatCount)
{
	this->mBrand = new char[strlen(brandName)+1];
	strcpy(this->mBrand, brandName);

	this->mType = ct;

	this->mColor = new char[strlen(colorName)+1];
	strcpy(this->mColor, colorName);

	this->mPower = power;

	this->mSeatCount = seatCount;

	this->mMileage = 0;
	this->mOilCount = 0;

	this->mMaster = NULL;
}

Car::Car(const char* brandName, CardType ct)
{
	//Car::Car(brandName, ct, "White");	//�ڹ��캯���м򵥵ص����������캯��ʱ�������һ�������ֲ����󣬶������Ķ���û�е��ù��캯��

	new (this)Car(brandName, ct, "White");	//Ӧ�����ڴ����󣬵��ñ�����Ĺ��캯����ʼ�����������߰ѳ�ʼ������д��һ����������
}

Car::Car(const Car& myCar)
{
	this->mBrand = new char[strlen(myCar.mBrand)+1];
	strcpy(this->mBrand, myCar.mBrand);

	this->mType = myCar.mType;

	this->mColor = new char[strlen(myCar.mColor)+1];
	strcpy(this->mColor, myCar.mColor);

	this->mPower = myCar.mPower;

	this->mSeatCount = myCar.mSeatCount;

	this->mMileage = myCar.mMileage;
	this->mOilCount = myCar.mOilCount;

	this->mMaster = myCar.mMaster;
}

Car::Car(const char *brandName)
{
	this->mBrand = new char[strlen(brandName)+1];
	strcpy(this->mBrand, brandName);

	this->mType = S1;

	this->mColor = new char[strlen("White")+1];
	strcpy(this->mColor, "White");

	this->mPower = 78;

	this->mSeatCount = 4;

	this->mMileage = 0;

	this->mOilCount = 0;

	this->mMaster = NULL;
}

Car::~Car(void)
{
	if (NULL != this->mBrand) 
	{
		delete[] this->mBrand;
		this->mBrand = NULL;
	}

	if (NULL != this->mColor)
	{
		delete[] this->mColor;
		this->mColor = NULL;
	}
}

void Car::operator=(const Car& myCar)
{
	if (NULL != this->mBrand) 
	{
		delete this->mBrand;
		this->mBrand = NULL;
	}

	if (NULL != this->mColor)
	{
		delete this->mColor;
		this->mColor = NULL;
	}

	this->mBrand = new char[strlen(myCar.mBrand)+1];
	strcpy(this->mBrand, myCar.mBrand);

	this->mType = myCar.mType;

	this->mColor = new char[strlen(myCar.mColor)+1];
	strcpy(this->mColor, myCar.mColor);

	this->mPower = myCar.mPower;

	this->mSeatCount = myCar.mSeatCount;

	this->mMileage = myCar.mMileage;

	this->mOilCount = myCar.mOilCount;

	this->mMaster = myCar.mMaster;
}

Car Car::operator ++()
{
	Car c = *this;

	this->mOilCount++;

	return c;
}

Car& Car::operator ++(int k)
{
	this->mOilCount++;

	return *this;
}

Car::operator int()
{
	return this->mMileage;
}

void Car::Run(int mMile)
{
	this->mMileage = this->mMileage + mMile;
	this->mOilCount -= mMile*6;
}

void Car::Show() const
{
	if (NULL != this->mMaster)
	{
		cout<<"==================CarInfo================="
			<<"\nMasterName: "<<this->mMaster->GetName()
			<<"\nBrandName: "<<this->mBrand
			<<"\nColorName: "<<this->mColor
			<<"\nMileage: "<<this->mMileage<<endl;
	}
	else
	{
		cout<<"==================CarInfo================="
			<<"\nMasterName: "<<""
			<<"\nBrandName: "<<this->mBrand
			<<"\nColorName: "<<this->mColor
			<<"\nMileage: "<<this->mMileage<<endl;
	}
}

void Car::SetMaster(Customer *pMaster)
{
	this->mMaster = pMaster;
}

void Car::ResetMileage()
{
	this->mMileage = 0;
}


#include "StdAfx.h"
#include "Customer.h"

Customer::Customer(const char* szName)
{
	strcpy(mName, szName);
	for(int i=0;i<10;i++) mCars[i] = NULL;

	BuyCarEvent = NULL;
	SellCarEvent = NULL;
}

Customer::~Customer(void)
{
	ClearCar();
}

bool Customer::BuyCar(Car *pCar)
{
	for(int i=0;i<10;i++)
	{
		if(NULL == mCars[i])
		{
			mCars[i] = pCar;
			pCar->SetMaster(this);

			if (NULL != BuyCarEvent) BuyCarEvent(mName, *pCar);

			return true;
		}
	}

	return false;
}

void Customer::SellCar(int iPos)
{
	if (iPos<0 || iPos >=10) return;

	if (NULL != mCars[iPos])
	{
		if (NULL != SellCarEvent) SellCarEvent(mName, *mCars[iPos]);

		delete mCars[iPos];
		mCars[iPos] = NULL;
	}
}

void Customer::ClearCar()
{
	for(int i=0;i<10;i++)
	{
		if (NULL != mCars[i]) 
		{
			delete mCars[i];
			mCars[i] = NULL;
		}
	}
}

const char * Customer::GetName()
{
	return mName;
}
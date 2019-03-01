// CPlusPlusDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Car.h"
#include "VolkswageCar.h"
#include "FordCar.h"
#include "TaurusJettaCar.h"
#include "Customer.h"

class A;
class A;
class B;

class A
{
public:
	int i;
	B *mB;

	void Show()
	{

	}
};

class B
{
public:
	int j;
	A *mA;
};

//全局函数
void EBuyCar(const char *szName, const Car& c)
{
	cout<<szName<<" Buy a "<<c.mBrand<<"!"<<endl;
}
void ESellCar(const char *szName, const Car& c)
{
	cout<<szName<<" Sell a "<<c.mBrand<<"!"<<endl;
}

class RunEvent
{
public:
	//成员函数
	void SubSellCar(const char *szName, const Car& c)
	{
		cout<<szName<<" Sell a "<<c.mBrand<<"!"<<endl;
	}

	//静态成员函数
	static void StaticSellCar(const char *szName, const Car& c)
	{
		cout<<szName<<" Sell a "<<c.mBrand<<"!"<<endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	//=================================================================
	//Car c1 = "BMW";		//调用转换构造函数，等同于Car c1("BMW");
	//c1++;				//调用后置++
	//++c1;				//调用前置++
	//c1>>12>>45>>12;		//调用三次>>
	//int iMileage = c1;	//调用类型转换重载函数
	//c1.Show();

	//Car c2("VK", S1);

	//VolkswageCar vc1;
	//vc1.Show();

	//=================================================================
	//TaurusJettaCar tjc;			//解决菱形继承的问题
	//tjc.Show();

	//=================================================================
	//Customer c("Chen Gui Quan");	//解决复合类循环定义问题
	//c.BuyCarEvent = &EBuyCar;					//指向全局函数
	//c.SellCarEvent = &ESellCar;	//指向静态成员函数

	//FordCar *fc = new FordCar();

	//VolkswageCar * vc = new VolkswageCar();

	//c.BuyCar(fc);
	//c.BuyCar(vc);

	//fc->Show();
	//vc->Show();

	//c.SellCar(0);
	//c.SellCar(1);

	//==================================================================
	//void (*pStaticSellCar)(const char *szName, const Car& c);  //指向类的静态成员函数
	//pStaticSellCar = &RunEvent::StaticSellCar;
	//pStaticSellCar("CF", VolkswageCar());

	//void (RunEvent::*pSubSellCar)(const char *szName, const Car& c);	//指向类的成员函数，一定要定义为类的函数指针
	//pSubSellCar = &RunEvent::SubSellCar;
	//RunEvent re;
	//(re.*pSubSellCar)("GQ", FordCar());		//调用成员函数

	return 0;
}


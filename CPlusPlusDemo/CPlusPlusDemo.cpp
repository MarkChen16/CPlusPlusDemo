// CPlusPlusDemo.cpp : �������̨Ӧ�ó������ڵ㡣
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

//ȫ�ֺ���
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
	//��Ա����
	void SubSellCar(const char *szName, const Car& c)
	{
		cout<<szName<<" Sell a "<<c.mBrand<<"!"<<endl;
	}

	//��̬��Ա����
	static void StaticSellCar(const char *szName, const Car& c)
	{
		cout<<szName<<" Sell a "<<c.mBrand<<"!"<<endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	//=================================================================
	//Car c1 = "BMW";		//����ת�����캯������ͬ��Car c1("BMW");
	//c1++;				//���ú���++
	//++c1;				//����ǰ��++
	//c1>>12>>45>>12;		//��������>>
	//int iMileage = c1;	//��������ת�����غ���
	//c1.Show();

	//Car c2("VK", S1);

	//VolkswageCar vc1;
	//vc1.Show();

	//=================================================================
	//TaurusJettaCar tjc;			//������μ̳е�����
	//tjc.Show();

	//=================================================================
	//Customer c("Chen Gui Quan");	//���������ѭ����������
	//c.BuyCarEvent = &EBuyCar;					//ָ��ȫ�ֺ���
	//c.SellCarEvent = &ESellCar;	//ָ��̬��Ա����

	//FordCar *fc = new FordCar();

	//VolkswageCar * vc = new VolkswageCar();

	//c.BuyCar(fc);
	//c.BuyCar(vc);

	//fc->Show();
	//vc->Show();

	//c.SellCar(0);
	//c.SellCar(1);

	//==================================================================
	//void (*pStaticSellCar)(const char *szName, const Car& c);  //ָ����ľ�̬��Ա����
	//pStaticSellCar = &RunEvent::StaticSellCar;
	//pStaticSellCar("CF", VolkswageCar());

	//void (RunEvent::*pSubSellCar)(const char *szName, const Car& c);	//ָ����ĳ�Ա������һ��Ҫ����Ϊ��ĺ���ָ��
	//pSubSellCar = &RunEvent::SubSellCar;
	//RunEvent re;
	//(re.*pSubSellCar)("GQ", FordCar());		//���ó�Ա����

	return 0;
}


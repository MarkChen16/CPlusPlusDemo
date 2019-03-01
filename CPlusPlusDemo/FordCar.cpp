#include "StdAfx.h"
#include "FordCar.h"


FordCar::FordCar(void):Car("Ford Taurus", S2)
{
	mCreateTime = time(0);
}


FordCar::~FordCar(void)
{
}

void FordCar::Show() const
{
	Car::Show();
	
	tm *ltm = localtime(&mCreateTime);
	cout<<"CreateTime: "<<ltm->tm_year+1900<<"-"<<ltm->tm_mon+1<<"-"<<ltm->tm_mday<<endl;
	//cout<<"CreateTime: "<<ctime(&mCreateTime);
}

/*
C++ STLû���ṩ����ʱ�����ͣ�ֻ��C���Ե�ctime��tm�ṹ

struct tm {
  int tm_sec;   // �룬������Χ�� 0 �� 59���������� 61
  int tm_min;   // �֣���Χ�� 0 �� 59
  int tm_hour;  // Сʱ����Χ�� 0 �� 23
  int tm_mday;  // һ���еĵڼ��죬��Χ�� 1 �� 31
  int tm_mon;   // �£���Χ�� 0 �� 11
  int tm_year;  // �� 1900 ���������
  int tm_wday;  // һ���еĵڼ��죬��Χ�� 0 �� 6��������������
  int tm_yday;  // һ���еĵڼ��죬��Χ�� 0 �� 365���� 1 �� 1 ������
  int tm_isdst; // ����ʱ
}
*/
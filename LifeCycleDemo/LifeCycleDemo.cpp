// LifeCycleDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LifeCycle.h"

//ȫ�ֱ�������������ǰҪ�������ȹ��������
CT c1(1);

void Fun()
{
	//��̬�ֲ���������һ��ʹ��ʱ��������ȫ�ֱ�������һ���ȹ��������
	static CT c2(2);

	CT c3(3);
	cout<<"Fun"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CT c4(4);

	//����ת�����캯������6ת��Ϊ��ʱ�����ٶԱ������и�ֵ
	c4 = 6;			
	cout<<"main begin"<<endl;

	//����飺������ΧҪ��������
	{
		CT ct5(5);
	}

	Fun();
	cout<<"main ends"<<endl;

	return 0;
}


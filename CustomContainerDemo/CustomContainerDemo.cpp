// CustomContainerDemo.cpp : ��������Զ������������������㷨�ͺ������󣬳�����������
//

#include "stdafx.h"
#include "CustomList.h"

#include <vector>
#include <functional>
#include <algorithm>

#include <iostream>
using namespace std;

//���ر�׼�������<<������
ostream & operator <<(ostream &os, CustomList<int>& cl)
{
	//ʹ���±����
	//os<<"CustomList: ";
	//for(int i=0;i<cl.size();i++)
	//{
	//	os<<cl[i]<<" ";
	//}
	//os<<endl;

	//ʹ���Զ������������
	os<<"CustomList: ";
	CustomList<int>::CLIterator iter = cl.begin();
	while(iter!=cl.end())
	{
		cout<<*iter++<<" ";
	};
	os<<endl;

	return os;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int il[20] = {24, 56, 49, 77, 2, 78, 93, 23, 12, 67, 31, 84, 73, 93, 95, 105, 10, 32, 65, 168};
	vector<int> v(il, il+20);

	CustomList<double> clDouble(100, 1.2);
	CustomList<int> cl(5, 0);
	cl[1] = 12;
	cl[3] = 57;

	cl.assign(il, il+20);			//����[il, il+20)���������Ԫ��
	cl.assign(v.begin(), v.end());	//����vector����������Ԫ��

	//�����Զ����㷨*****************************
	MySort(cl.begin(), cl.end(), less<int>());	//���ú���������������
	cout<<cl;

	MySort(cl.begin(), cl.end(), MyLess<int>());	//�Զ��庯�����󣺸�����������
	cout<<cl;

	//���������㷨********************************
	//ͳ�ƴ���100�ĸ���
	int iCount = count_if(cl.begin(), cl.end(), bind2nd(greater<int>(), 100));	//bind1st��bind2ndת����Ԫ������һԪ����
	cout<<"greater 100 count is "<<iCount<<endl;

	sort(cl.begin(), cl.end());		//���°���������
	cout<<cl;

	//�������в���ĳ��ֵ�����ص�������û���ҵ��򷵻�_last����������
	CustomList<int>::CLIterator iterFind = find(cl.begin(), cl.end()-10, 31);	//����������������31
	if (iterFind == cl.end()-10) cout<<"Don't find it."<<endl;
	else cout<<"Find it."<<endl;

	return 0;
}


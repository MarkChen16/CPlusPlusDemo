#pragma once
#include <iostream>

using namespace std;

template<class T1, class T2>
class MyList;

//����cout��<<������������ֱ�����MyList�����Ϣ
template<class T1, class T2>
ostream& operator <<(ostream& os, MyList<T1, T2> list);

template<class T1, class T2>
void Show(MyList<T1, T2> list);

//ģ���ඨ��
template<class T1, class T2>
class MyList
{
public:
	MyList(void);
	virtual ~MyList(void);

	//����ǿ��ת����
	operator int();

	void Set(int intIndex, T1 t1, T2 t2);

	//ȫ����Ԫ����
	friend void Show(MyList<T1, T2> list);

	//��̬��Ա����
	static int ListCount;

private:
	T1 mT1[10];
	T2 mT2[10];
};

//ģ����̳�ģ����
template<class T1>
class StrongList:public MyList<T1, T1>
{
public:

private:

};

//��ͨ��̳�ģ����
class IntList:public MyList<int, int>
{
public:


private:

};

//ģ����ľ�̬��Ա������ʼ����ǰ��Ҫ���� template<>����Ҫ��ָ��ģ���������Ϊstatic��Ա��ÿ������һ��
template<> int MyList<int, double>::ListCount = 0;
template<> int MyList<int, int>::ListCount = 0;

template<class T1, class T2>
void Show(MyList<T1, T2> list)
{
	cout<<"mT1: "<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<list.mT1[i]<<" ";
	}
	cout<<endl;

	cout<<"mT2: "<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<list.mT2[i]<<" ";
	}
	cout<<endl;
}

template<class T1, class T2>
ostream& operator <<(ostream& os, MyList<T1, T2> list)
{
	os<<list;
	return os;
}

template<class T1, class T2>
MyList<T1, T2>::MyList(void)
{
	for(int i=0;i<10;i++)
	{
		mT1[i] = 0;
		mT2[2] = 0;
	}
}

template<class T1, class T2>
MyList<T1, T2>::~MyList(void)
{
}

template<class T1, class T2>
MyList<T1, T2>::operator int()
{
	return MyList<T1, T2>::ListCount;
}

template<class T1, class T2>
void MyList<T1, T2>::Set(int intIndex, T1 t1, T2 t2)
{
	mT1[intIndex] = t1;
	mT2[intIndex] = t2;
}


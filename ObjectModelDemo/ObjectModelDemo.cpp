// ObjectModelDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//#include <windows.h>
#include <string>

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
class A1
{
public:
	A1(int i):mi(i){cout<<mi<<": A1()"<<endl;}
	virtual ~A1(){cout<<mi<<": ~A1()"<<endl;}

	virtual int GetLevel(){return 1;}

private:
	int mi;
};
////////////////////////////////////////////////////////////
class A2
{
public:
	A2(int i):mi(i){cout<<mi<<": A2()"<<endl;}
	virtual ~A2(){cout<<mi<<": ~A2()"<<endl;}

	virtual int GetLevel(){return 1;}

private:
	int mi;
};
////////////////////////////////////////////////////////////
class B1:public A1
{
public:
	B1(int i):A1(i), mi(i){cout<<mi<<": B1()"<<endl;}
	virtual ~B1(){cout<<mi<<": ~B1()"<<endl;}

	//��дA1��GetLevel
	virtual int GetLevel(){return 2;}

	//���B1_GetLevel
	virtual int B1_GetLevel(){return 2;}

private:
	int mi;
};
////////////////////////////////////////////////////////////
class B2:public A1,public A2
{
public:
	B2(int i):A1(i), A2(i), mi(i){cout<<mi<<": B2()"<<endl;}
	virtual ~B2(){cout<<mi<<": ~B2()"<<endl;}

	//��дA1��GetLevel
	virtual int GetLevel(){return 2;}

	//���B1_GetLevel
	virtual int B2_GetLevel(){return 2;}

private:
	int mi;
};
////////////////////////////////////////////////////////////
class B3:public virtual A1
{
public:
	B3(int i):A1(i), mi(i){cout<<mi<<": B3()"<<endl;}
	virtual ~B3(){cout<<mi<<": ~B3()"<<endl;}

	//��дA1��GetLevel
	virtual int GetLevel(){return 2;}

	//���B1_GetLevel
	virtual int B3_GetLevel(){return 2;}

private:
	int mi;
};
////////////////////////////////////////////////////////////
class B4:public virtual A1
{
public:
	B4(int i):A1(i), mi(i){cout<<mi<<": B4()"<<endl;}
	virtual ~B4(){cout<<mi<<": ~B4()"<<endl;}

	//���B1_GetLevel
	virtual int B4_GetLevel(){return 2;}

private:
	int mi;
};
////////////////////////////////////////////////////////////
class C:public B3, public B4
{
public:
	C(int i):A1(i), B3(i), B4(i), mi(i){cout<<mi<<": C()"<<endl;}
	virtual ~C(){cout<<mi<<": ~C()"<<endl;}

	//���B1_GetLevel
	virtual int C_GetLevel(){return 2;}

private:
	int mi;
};
////////////////////////////////////////////////////////////

typedef unsigned long DWORD;

struct TypeDescriptor
{
    DWORD ptrToVTable;
    DWORD spare;
    char name[8];
};

struct PMD
{

    int mdisp;  //member displacement

    int pdisp;  //vbtable displacement

    int vdisp;  //displacement inside vbtable

};
struct RTTIBaseClassDescriptor

{

    struct TypeDescriptor* pTypeDescriptor; //type descriptor of the class

    DWORD numContainedBases; //number of nested classes following in the Base Class Array

    struct PMD where;        //pointer-to-member displacement info

    DWORD attributes;        //flags, usually 0

};

struct RTTIClassHierarchyDescriptor
{

    DWORD signature;      //always zero?

    DWORD attributes;     //bit 0 set = multiple inheritance, bit 1 set = virtual inheritance

    DWORD numBaseClasses; //number of classes in pBaseClassArray

    struct RTTIBaseClassArray* pBaseClassArray;

};

struct RTTICompleteObjectLocator

{

    DWORD signature; //always zero ?

    DWORD offset;    //offset of this vtable in the complete class

    DWORD cdOffset;  //constructor displacement offset

    struct TypeDescriptor* pTypeDescriptor; //TypeDescriptor of the complete class

    struct RTTIClassHierarchyDescriptor* pClassDescriptor; //describes inheritance hierarchy


};

void RTTIDemo()
{
	//typeid�ؼ��֣�����ָ�����������ָ��ʵ�����͵�type_info�ṹ
	//auto�ؼ��֣��������ݵ����Ͷ�̬ʹ��ʵ������
	//dynamic_cast<T*>����ȫת�������RTTI��ʵ�����ͣ�����ָ��-��������ָ�벻��ȫ������NULL
	B1 b(1);
	B2 b2(2);
	B3 b3(3);

	A1 *pA1 = dynamic_cast<A1 *>(&b);	//�ɹ�
	C *pC = dynamic_cast<C *>(&b);		//ʧ��

	auto pWhat = *pA1;		//���ø��ƹ��캯��
	cout<<"TypeName: "<<typeid(pWhat).name()<<endl;
	cout<<"GetLevel: "<<pWhat.GetLevel()<<endl;

	//static_cast<T*>��ֱ��ת��������ƫ���������������Ͱ�ȫ��飻����ָ��-��������ָ�루����ȫ��
	pA1 = static_cast<A1 *>(&b);		//�ɹ�
	//pC = static_cast<C *>(&b);			//�ɹ�������ȫ����������ʾ����ת����Ч

	//reinterpret_cast<T*>��C++��ǿ��ת����ֱ���ڴ�ӳ�䣬����ƫ�Ƽ��㣻(�ڼ̳й�ϵ����ò�Ҫʹ��)
	pA1 = reinterpret_cast<A1 *>(&b2);		//�ɹ�(���̳У�ȡ��һ�����࣬��Ϊ�ڴ����)
	cout<<"B1::GetLevel = "<<pA1->GetLevel()<<endl;

	A2 *pA2 = reinterpret_cast<A2 *>(&b2);		//ʧ��(��̳У�ȡ�ڶ������������⣬��Ҫ����ƫ������ʹ��static_cast)
	cout<<"B2::GetLevel = "<<pA2->GetLevel()<<endl;

	pA1 = reinterpret_cast<A1 *>(&b3);		//ʧ��(������̳еĶ���ģ���������̳в�һ�����������ں�����ȫ���ֽڼ��)
	//cout<<"B3::GetLevel = "<<pA1->GetLevel()<<endl;

	pC = reinterpret_cast<C *>(&b);		//�ɹ���������ȫ��������ڴ��ȡʧ�ܵ����

	//const_cast<T*>������ת��Ϊ�ǳ���ͬ�������ͣ�
	const B1 *pcB1 = &b;
	B1 *pB1 = const_cast<B1 *>(pcB1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//�޼̳�
	A1 a1(1);

	//���̳У���д���������麯�����ڵ�һ���������������µ��麯��=======================================
	B1 b1(2);
	int *pb1 = (int *)(&b1);

	//ͨ��RTTI���ƻ�ȡtype_info�ṹ��������׵�ַ�����ָ�룬�������4���ֽ�ָ��type_info�ṹ
	cout << "type_info��Ϣ��ַ��" << ((int*)*pb1 - 1) << endl;

    //type_info�����˼̳й�ϵ�������������ȡ���͵�����
    RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*pb1 - 1));
    string classname(str.pTypeDescriptor->name);
    classname = classname.substr(4,classname.find("@@")-4);
    cout<<classname <<endl;

	cout << "����d����ʼ�ڴ��ַ��" << pb1 << endl;
    cout << "���ָ�룺" << (int*)(&b1) << endl;
    cout << "�麯���� �� ��1��������ַ(����������)��" << (int*)*pb1 << endl;
    cout << "�麯���� �� ��2��������ַ(��д��GetLevel����)��" << ((int*)*pb1 + 1) << endl;
	cout << "�麯���� �� ��3��������ַ(������ӵ��麯��B1_GetLevel): " << ((int*)*pb1 + 2)  << endl;

    typedef int(*GetLevelFun)();
    GetLevelFun pFun1 = (GetLevelFun)*((int*)*pb1 + 1);	//������д���GetLevel
	cout<<"������д���GetLevel: "<<pFun1()<<endl;

    GetLevelFun pFun2 = (GetLevelFun)*((int*)*pb1 + 2);	//������������麯��B1_GetLevel
	cout<<"������������麯��B1_GetLevel: "<<pFun2()<<endl;

	//��ȡ�����mi
	cout<<"�����mi��"<<*(int *)(pb1+1)<<endl;

	//��ȡ�����mi
	cout<<"�����mi��"<<*(int *)(pb1+2)<<endl;

	//��̳У��������࿿ǰ����д���л��������������ڵ�һ��������������µ��麯���������ڴ���룻
	//�޸Ļ������ʱ�����ڹ��캯�������������͸�ֵ����
	B2 b2(3);

	//����̳�
	B3 b3(4);

	//������̳У����������ͳ�Ա�������ĸ�ȫ���ֽڷָ���������������Ͷ����Լ��Ķ���������̳й�ϵ����
	//���������д��������������麯��(���������)��
	C c(5);

	RTTIDemo();
	
	return 0;
}

/*
����Ҫ�㣺

һ�������С
	��ͨ�̳����С=���л���+������
	��̳����С=���л���+������+4
	�յ�����=1�ֽڣ�����һ��char����

������Ա���ݷ��ʣ�ͨ�����ݵ���ʼ��ַ+ƫ����ȡ��

������̬�󶨺Ͷ�̬��
	��̬�󶨣���Ա�����;�̬����ͨ���������Ͳ�����
	��̬�󶨣��麯��ͨ�������麯����ȷ��������ַ���麯��ʵ�ֶ�̬��Ҫһ���ɱ�

�ġ���̬ʵ��
	ʵ��ԭ��������麯����������������д(���ù��캯�������������͸�ֵ������ʱ��)
	ʵ�ַ�ʽ��ͨ�������ָ���������ʹ��������

�塢�������������Ϊ�麯���Ǳ�Ҫ��
	ԭ��ͨ��newһ����������󣬸�������ָ�룬����delete����ָ��ʱ�����������������������麯��������벻����������������������

*/
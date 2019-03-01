// ObjectModelDemo.cpp : 定义控制台应用程序的入口点。
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

	//重写A1的GetLevel
	virtual int GetLevel(){return 2;}

	//添加B1_GetLevel
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

	//重写A1的GetLevel
	virtual int GetLevel(){return 2;}

	//添加B1_GetLevel
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

	//重写A1的GetLevel
	virtual int GetLevel(){return 2;}

	//添加B1_GetLevel
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

	//添加B1_GetLevel
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

	//添加B1_GetLevel
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
	//typeid关键字：返回指针或者引用所指的实际类型的type_info结构
	//auto关键字：根据数据的类型动态使用实际类型
	//dynamic_cast<T*>：安全转换，检查RTTI的实际类型；基类指针-》派生类指针不安全，返回NULL
	B1 b(1);
	B2 b2(2);
	B3 b3(3);

	A1 *pA1 = dynamic_cast<A1 *>(&b);	//成功
	C *pC = dynamic_cast<C *>(&b);		//失败

	auto pWhat = *pA1;		//调用复制构造函数
	cout<<"TypeName: "<<typeid(pWhat).name()<<endl;
	cout<<"GetLevel: "<<pWhat.GetLevel()<<endl;

	//static_cast<T*>：直接转换，计算偏移量，但不做类型安全检查；基类指针-》派生类指针（不安全）
	pA1 = static_cast<A1 *>(&b);		//成功
	//pC = static_cast<C *>(&b);			//成功，不安全，编译器提示类型转换无效

	//reinterpret_cast<T*>：C++的强制转换，直接内存映射，不做偏移计算；(在继承关系中最好不要使用)
	pA1 = reinterpret_cast<A1 *>(&b2);		//成功(单继承，取第一个基类，因为内存对齐)
	cout<<"B1::GetLevel = "<<pA1->GetLevel()<<endl;

	A2 *pA2 = reinterpret_cast<A2 *>(&b2);		//失败(多继承，取第二个基类有问题，需要计算偏移量，使用static_cast)
	cout<<"B2::GetLevel = "<<pA2->GetLevel()<<endl;

	pA1 = reinterpret_cast<A1 *>(&b3);		//失败(由于虚继承的对象模型与其他继承不一样，虚基类放在后面以全零字节间隔)
	//cout<<"B3::GetLevel = "<<pA1->GetLevel()<<endl;

	pC = reinterpret_cast<C *>(&b);		//成功，但不安全，会出现内存读取失败的情况

	//const_cast<T*>：常量转换为非常量同样的类型；
	const B1 *pcB1 = &b;
	B1 *pB1 = const_cast<B1 *>(pcB1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//无继承
	A1 a1(1);

	//单继承：重写基类虚表的虚函数、在第一个基类虚表中添加新的虚函数=======================================
	B1 b1(2);
	int *pb1 = (int *)(&b1);

	//通过RTTI机制获取type_info结构，对象的首地址是虚表指针，虚表以上4个字节指向type_info结构
	cout << "type_info信息地址：" << ((int*)*pb1 - 1) << endl;

    //type_info描述了继承关系，可以在里面获取类型的名称
    RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*pb1 - 1));
    string classname(str.pTypeDescriptor->name);
    classname = classname.substr(4,classname.find("@@")-4);
    cout<<classname <<endl;

	cout << "对象d的起始内存地址：" << pb1 << endl;
    cout << "虚表指针：" << (int*)(&b1) << endl;
    cout << "虚函数表 — 第1个函数地址(虚析构函数)：" << (int*)*pb1 << endl;
    cout << "虚函数表 — 第2个函数地址(重写后GetLevel函数)：" << ((int*)*pb1 + 1) << endl;
	cout << "虚函数表 — 第3个函数地址(子类添加的虚函数B1_GetLevel): " << ((int*)*pb1 + 2)  << endl;

    typedef int(*GetLevelFun)();
    GetLevelFun pFun1 = (GetLevelFun)*((int*)*pb1 + 1);	//调用重写后的GetLevel
	cout<<"调用重写后的GetLevel: "<<pFun1()<<endl;

    GetLevelFun pFun2 = (GetLevelFun)*((int*)*pb1 + 2);	//调用子类的新虚函数B1_GetLevel
	cout<<"调用子类的新虚函数B1_GetLevel: "<<pFun2()<<endl;

	//获取基类的mi
	cout<<"基类的mi："<<*(int *)(pb1+1)<<endl;

	//获取子类的mi
	cout<<"子类的mi："<<*(int *)(pb1+2)<<endl;

	//多继承：有虚表基类靠前，重写所有基类的虚表函数，并在第一个基类虚表增加新的虚函数，保持内存对齐；
	//修改基类虚表时机：在构造函数、析构函数和赋值操作
	B2 b2(3);

	//单虚继承
	B3 b3(4);

	//菱形虚继承：虚基类的虚表和成员数据以四个全零字节分隔放在最后，其他类型都有自己的独立虚表，按继承关系排列
	//子类可以重写所有其他基类的虚函数(包括虚基类)；
	C c(5);

	RTTIDemo();
	
	return 0;
}

/*
其他要点：

一、对象大小
	普通继承类大小=所有基类+派生类
	虚继承类大小=所有基类+派生类+4
	空的类型=1字节，安插一个char进来

二、成员数据访问：通过数据的起始地址+偏移量取得

三、静态绑定和动态绑定
	静态绑定：成员函数和静态函数通过函数名和参数绑定
	动态绑定：虚函数通过查找虚函数表确定函数地址，虚函数实现多态需要一定成本

四、多态实现
	实现原理：基类的虚函数表允许派生类重写(调用构造函数、析构函数和赋值操作的时候)
	实现方式：通过基类的指针或者引用使用派生类

五、基类的析构函数为虚函数是必要的
	原因：通过new一个派生类对象，赋给基类指针，后面delete基类指针时，如果基类的析构函数不是虚函数，则编译不会调用派生类的析构函数；

*/
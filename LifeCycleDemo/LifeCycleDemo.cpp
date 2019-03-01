// LifeCycleDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LifeCycle.h"

//全局变量：程序启动前要创建，先构造后析构
CT c1(1);

void Fun()
{
	//静态局部变量：第一次使用时创建，跟全局变量放在一起，先构造后析构
	static CT c2(2);

	CT c3(3);
	cout<<"Fun"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CT c4(4);

	//调用转换构造函数，将6转换为临时对象，再对变量进行赋值
	c4 = 6;			
	cout<<"main begin"<<endl;

	//代码块：超出范围要析构变量
	{
		CT ct5(5);
	}

	Fun();
	cout<<"main ends"<<endl;

	return 0;
}


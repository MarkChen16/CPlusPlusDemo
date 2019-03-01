// CustomContainerDemo.cpp : 这个例子自定义容器、迭代器、算法和函数对象，除了适配器。
//

#include "stdafx.h"
#include "CustomList.h"

#include <vector>
#include <functional>
#include <algorithm>

#include <iostream>
using namespace std;

//重载标准输出流的<<操作符
ostream & operator <<(ostream &os, CustomList<int>& cl)
{
	//使用下标遍历
	//os<<"CustomList: ";
	//for(int i=0;i<cl.size();i++)
	//{
	//	os<<cl[i]<<" ";
	//}
	//os<<endl;

	//使用自定义迭代器遍历
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

	cl.assign(il, il+20);			//复制[il, il+20)区间的所有元素
	cl.assign(v.begin(), v.end());	//复制vector容量的所有元素

	//调用自定义算法*****************************
	MySort(cl.begin(), cl.end(), less<int>());	//内置函数对象：升序排列
	cout<<cl;

	MySort(cl.begin(), cl.end(), MyLess<int>());	//自定义函数对象：个数升序排列
	cout<<cl;

	//调用内置算法********************************
	//统计大于100的个数
	int iCount = count_if(cl.begin(), cl.end(), bind2nd(greater<int>(), 100));	//bind1st、bind2nd转换二元函数成一元函数
	cout<<"greater 100 count is "<<iCount<<endl;

	sort(cl.begin(), cl.end());		//重新按升序排列
	cout<<cl;

	//在容器中查找某个值，返回迭代器；没有找到则返回_last参数迭代器
	CustomList<int>::CLIterator iterFind = find(cl.begin(), cl.end()-10, 31);	//在容量左半区间查找31
	if (iterFind == cl.end()-10) cout<<"Don't find it."<<endl;
	else cout<<"Find it."<<endl;

	return 0;
}


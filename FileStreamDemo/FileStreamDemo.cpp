// FileStreamDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//标准输入输出流和格式
#include <iostream>
#include <iomanip>

//文件输入输出流
#include <fstream>
/*
文本文件的换行：
windows系统为\x0d\x0a，读出时自动去掉\x0d，写入时自动加上\x0d；
Linux系统为\x0a
MacOS系统为\x0d

但是使用二进制方式读写文件就没有这些问题；
*/

//STL字符串
#include <string>	//string、wstring
//字符串输入输出流，从字符串中读取数据，或者写数据到字符串
#include <sstream>	//istringstream、ostringstream

//STL容器和算法
#include <vector>	//动态数组
#include <deque>	//双向队列
#include <list>		//双向链表
#include <set>		//集合
#include <map>		//映射
#include <stack>	//栈
#include <queue>	//队列
#include <bitset>	//位集合

#include <algorithm>	//算法

#include <functional>	//函数对象

//顺序容器：vector动态数组(内存连续，随机存取，前面插入删除慢，后面速度快，支持随机访问迭代器)
//			deque双向队列(部分内存连续，随机存取，中间插入删除慢，前后速度快，支持随机访问迭代器)
//			list双向链表(不连续，不能随机存取，快速插入删除，支持双向迭代器)

//关联容器：set/multiset集合(内部排序的，使用平衡二叉树实现，插入删除和检索都是log(n)，支持双向迭代器)
//			map/multimap映射(内部以frist从小到大排序的, frist、second分别是第一个和第二个元素值，支持双向迭代器)


/*
顺序容器和关联容器常用的成员函数：
begin()指向第一个元素
end()指向最后一个元素后面的位置
rbegin()指向最后一个元素
rend()指向第一元素前面的位置
erase()删除元素，可能会使迭代器失效
clear()删除所有元素

顺序容器常用的成员函数：
front()返回第一个元素的引用
back()返回最后一个元素的引用
push_back()在后面增加新元素
pop_back()在删除后面的元素
*/

//注意：容器中的元素都是通过复制的方式添加的，最好重载=和<等操作符函数，方便排序算法操作；


//特殊容器：stack栈(先进后出，top, bottom，出栈入栈都是在top上操作)
//			queue队列(先进先出，rear, front，在前面出，在后面入)
//			priority_queue优先级队列(内部以优先级来排序)
//			bitset(位集合)

//迭代器：双向迭代器、反向迭代器、常量迭代器、插入迭代器

//sort排序算法和binary_search二分查找算法需要随机访问迭代器
//find查找算法的判断根据是x小于y和y小于x同时不成立，则认为x等于y；

/*
template<class InIt, class T>
InIt find(InIt first, InIt last, const T& val);
在容器范围[first, last)中查找等于val值的元素，不包括last，算法范围都是左闭右开的区间；
如果查到，返回指向元素的迭代器，否则返回last；

关系定义：元素的大小等于关系都是程序员自定义的，1不一定小于2，也可以定义1大于2；
*/

using namespace std;

//定义数据结构
struct Student
{
	//string Name;  只能使用基本类型，不能使用复合类，因为动态分配的数据在析构时会出现问题
	char Name[10];
	int Age;
	int Sorce;
};

bool Cmp(Student& s1, Student &s2)
{
	if (s1.Sorce >= s2.Sorce) return true;
	else return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//初始化数据
	Student ss[3];
	strcpy(ss[0].Name, "Jone");
	ss[0].Age = 16;
	ss[0].Sorce = 78;

	strcpy(ss[1].Name, "Wendy");
	ss[1].Age = 15;
	ss[1].Sorce = 8;

	strcpy(ss[2].Name, "James");
	ss[2].Age = 9;
	ss[2].Sorce = 82;

	//使用容器复制数组
	vector<Student> v(ss, ss+3);

	//使用容量算法进行排序
	sort(v.begin(), v.end(), Cmp);	//不能没有Cmp，因为Student没有重载<操作符

	//保存数据到二进制文件
	ofstream fSave("Student.txt", ios::out|ios::binary);
	if (!fSave) return 0;

	//保存所有数据
	vector<Student>::const_iterator citer;		//使用的是常量迭代器
	for(citer=v.cbegin();citer!=v.cend();citer++)
	{
		const Student &s = *citer;				//返回的是常量引用
		fSave.write((char *)(&s), sizeof(Student));
	}

	fSave.close();

	//修改第三个学生的名字
	fstream fRead("Student.txt", ios::in|ios::out|ios::binary);

	fRead.seekp(sizeof(Student)*2, ios::beg);	//移动文件指针
	const char*szName = "GuiQuan";
	fRead.write(szName, strlen(szName)+1);	//长度加上1，写入字符串结束符\0
	fRead.seekp(0, ios::beg);
	
	//读取所有数据
	Student sRead;
	while(fRead.read((char *)(&sRead), sizeof(Student)))
	{
		cout<<setw(10)<<setiosflags(ios_base::left)<<setfill('*')<<sRead.Name;
		cout<<setw(10)<<setfill(' ')<<sRead.Age<<setw(10)<<sRead.Sorce<<endl;
	}

	fRead.close();

	return 0;
}


#pragma once

#include <iterator>
using namespace std;

//注意：模板类或者模板函数的声明和定义都要放在头文件
//编译器需要在声明时就要知道模板的实现，在使用时才能实例化模板类，不然链接器就要报错，无法找到模板函数的实现；

//自定义算法===============================================================
template<class _InIt, class _Pr>
void MySort(_InIt _frist, _InIt _last, _Pr _Pred)
{
	if (_frist == _last) return;

	//冒泡排序算法
	for(_InIt _b1 = _frist;_b1 != _last;_b1++)		//每次循环，把最值放在最后
	{
		int iDistance = distance(&(*_b1), &(*_last));

		for(_InIt _b2 = _frist;_b2 != _frist + (iDistance - 1);_b2++)
		{
			//每次比较相邻的元素，最值移到后一个元素
			if (!_Pred(*_b2, *(_b2+1)))
			{
				auto temp = *_b2;		//auto根据结果自动识别类型
				*_b2 = *(_b2+1);
				*(_b2 + 1) = temp;
			}
		}
	}

	//算法对迭代器要求有=  !=  +  ++  *操作符

	//冒泡排序算法
    //int i, j;  T temp;
    //for (i = 0; i < len - 1; i++)
    //    for (j = 0; j < len - 1 - i; j++)
    //    if (arr[j] > arr[j + 1])
    //    {
    //        temp = arr[j];
    //        arr[j] = arr[j + 1];
    //        arr[j + 1] = temp;
    //    }
}

//自定义函数类=============================================================
template<class T>
class MyLess
{
public:
	bool operator ()(const T& t1, const T& t2);
};

template<class T>
bool MyLess<T>::operator ()(const T& t1, const T& t2)
{
	return (t1 % 10) < (t2 % 10);
}

//自定义容器类=============================================================
template<class T>
class CustomList
{
public:
	//内嵌迭代器
	class CLIterator:public iterator<::input_iterator_tag, T>
	{
	public:
		//构造
		CLIterator(T *p)
		{
			mPtr = p;
		}

		//赋值
		void operator =(const CLIterator &iter)
		{
			mPtr = iter.mPtr;
		}

		//不等于
		bool operator !=(const CLIterator &iter)
		{
			return mPtr != iter.mPtr;
		}

		//等于
		bool operator ==(const CLIterator &iter)
		{
			return mPtr == iter.mPtr;
		}

		//小于
		bool operator <(const CLIterator &iter)
		{
			return mPtr<iter.mPtr;
		}

		//大于
		bool operator >(const CLIterator &iter)
		{
			return mPtr>iter.mPtr;
		}

		//前缀自加
		CLIterator& operator ++()
		{
			mPtr++;		//前缀返回本身

			return *this;
		}

		//后缀自加
		CLIterator operator ++(int)
		{
			CLIterator newIter(mPtr++);

			return newIter;
		}

		//前缀自减
		CLIterator& operator --()
		{
			mPtr--;		//前缀返回本身

			return *this;
		}

		//后缀自减
		CLIterator operator --(int)
		{
			CLIterator newIter(mPtr--);

			return newIter;
		}

		//加上整数
		CLIterator operator +(int i)
		{
			return CLIterator(mPtr+i);
		}

		//减去整数
		CLIterator operator -(int i)
		{
			return CLIterator(mPtr-i);
		}

		//两个迭代器相减
		int operator -(const CLIterator& iter)
		{
			return ::distance(iter.mPtr, mPtr);
		}

		//取值
		T& operator *()
		{
			return *mPtr;
		}

	private:
		T *mPtr;
	};

public:
	CustomList(int intSize, T val)
	{
		mCount = intSize;
		mElems = new T[intSize];

		for(int i=0;i<intSize;i++) mElems[i] = val;
	}

	~CustomList(void)
	{
		if (NULL != mElems)
		{
			delete[] mElems;
			mElems = NULL;
		}
	}

	//赋值函数
	template<class _InIt>
	void assign(_InIt _frist, _InIt _last)
	{
		int iCount = ::distance(_frist, _last);

		if (iCount<= 0) return;

		if (NULL != mElems)
		{
			delete[] mElems;
			mElems = NULL;
		}

		mElems = new T[iCount];
		mCount = iCount;
		
		int intTemp = 0;
		do
		{
			mElems[intTemp++] = *_frist++;
		}
		while(_frist!=_last);
	}

	//下标随机访问
	T& operator[](int i){
		return mElems[i];
	}

	//返回指向第一个元素的位置
	CLIterator begin(){
		return CLIterator(mElems);
	}

	//返回指向最后的元素后面的位置
	CLIterator end(){
		return CLIterator(mElems + mCount);
	}

	//返回容器的大小
	int size() const {
		return mCount;
	}

private:
	T* mElems;
	int mCount;
};



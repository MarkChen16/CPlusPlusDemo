#pragma once

#include <iterator>
using namespace std;

//ע�⣺ģ�������ģ�庯���������Ͷ��嶼Ҫ����ͷ�ļ�
//��������Ҫ������ʱ��Ҫ֪��ģ���ʵ�֣���ʹ��ʱ����ʵ����ģ���࣬��Ȼ��������Ҫ�����޷��ҵ�ģ�庯����ʵ�֣�

//�Զ����㷨===============================================================
template<class _InIt, class _Pr>
void MySort(_InIt _frist, _InIt _last, _Pr _Pred)
{
	if (_frist == _last) return;

	//ð�������㷨
	for(_InIt _b1 = _frist;_b1 != _last;_b1++)		//ÿ��ѭ��������ֵ�������
	{
		int iDistance = distance(&(*_b1), &(*_last));

		for(_InIt _b2 = _frist;_b2 != _frist + (iDistance - 1);_b2++)
		{
			//ÿ�αȽ����ڵ�Ԫ�أ���ֵ�Ƶ���һ��Ԫ��
			if (!_Pred(*_b2, *(_b2+1)))
			{
				auto temp = *_b2;		//auto���ݽ���Զ�ʶ������
				*_b2 = *(_b2+1);
				*(_b2 + 1) = temp;
			}
		}
	}

	//�㷨�Ե�����Ҫ����=  !=  +  ++  *������

	//ð�������㷨
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

//�Զ��庯����=============================================================
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

//�Զ���������=============================================================
template<class T>
class CustomList
{
public:
	//��Ƕ������
	class CLIterator:public iterator<::input_iterator_tag, T>
	{
	public:
		//����
		CLIterator(T *p)
		{
			mPtr = p;
		}

		//��ֵ
		void operator =(const CLIterator &iter)
		{
			mPtr = iter.mPtr;
		}

		//������
		bool operator !=(const CLIterator &iter)
		{
			return mPtr != iter.mPtr;
		}

		//����
		bool operator ==(const CLIterator &iter)
		{
			return mPtr == iter.mPtr;
		}

		//С��
		bool operator <(const CLIterator &iter)
		{
			return mPtr<iter.mPtr;
		}

		//����
		bool operator >(const CLIterator &iter)
		{
			return mPtr>iter.mPtr;
		}

		//ǰ׺�Լ�
		CLIterator& operator ++()
		{
			mPtr++;		//ǰ׺���ر���

			return *this;
		}

		//��׺�Լ�
		CLIterator operator ++(int)
		{
			CLIterator newIter(mPtr++);

			return newIter;
		}

		//ǰ׺�Լ�
		CLIterator& operator --()
		{
			mPtr--;		//ǰ׺���ر���

			return *this;
		}

		//��׺�Լ�
		CLIterator operator --(int)
		{
			CLIterator newIter(mPtr--);

			return newIter;
		}

		//��������
		CLIterator operator +(int i)
		{
			return CLIterator(mPtr+i);
		}

		//��ȥ����
		CLIterator operator -(int i)
		{
			return CLIterator(mPtr-i);
		}

		//�������������
		int operator -(const CLIterator& iter)
		{
			return ::distance(iter.mPtr, mPtr);
		}

		//ȡֵ
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

	//��ֵ����
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

	//�±��������
	T& operator[](int i){
		return mElems[i];
	}

	//����ָ���һ��Ԫ�ص�λ��
	CLIterator begin(){
		return CLIterator(mElems);
	}

	//����ָ������Ԫ�غ����λ��
	CLIterator end(){
		return CLIterator(mElems + mCount);
	}

	//���������Ĵ�С
	int size() const {
		return mCount;
	}

private:
	T* mElems;
	int mCount;
};



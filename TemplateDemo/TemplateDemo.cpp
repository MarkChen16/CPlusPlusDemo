// TemplateDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//MyList<double, int> ml;
	//int i = ml.ListCount;		//MyList<double, int>::ListCountû�ж���

	MyList<int, double> ml1;
	int i = ml1.ListCount;

	return 0;
}


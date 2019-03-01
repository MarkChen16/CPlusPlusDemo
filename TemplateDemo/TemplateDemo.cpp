// TemplateDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//MyList<double, int> ml;
	//int i = ml.ListCount;		//MyList<double, int>::ListCount没有定义

	MyList<int, double> ml1;
	int i = ml1.ListCount;

	return 0;
}


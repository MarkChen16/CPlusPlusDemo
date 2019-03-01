// FileStreamDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//��׼����������͸�ʽ
#include <iostream>
#include <iomanip>

//�ļ����������
#include <fstream>
/*
�ı��ļ��Ļ��У�
windowsϵͳΪ\x0d\x0a������ʱ�Զ�ȥ��\x0d��д��ʱ�Զ�����\x0d��
LinuxϵͳΪ\x0a
MacOSϵͳΪ\x0d

����ʹ�ö����Ʒ�ʽ��д�ļ���û����Щ���⣻
*/

//STL�ַ���
#include <string>	//string��wstring
//�ַ�����������������ַ����ж�ȡ���ݣ�����д���ݵ��ַ���
#include <sstream>	//istringstream��ostringstream

//STL�������㷨
#include <vector>	//��̬����
#include <deque>	//˫�����
#include <list>		//˫������
#include <set>		//����
#include <map>		//ӳ��
#include <stack>	//ջ
#include <queue>	//����
#include <bitset>	//λ����

#include <algorithm>	//�㷨

#include <functional>	//��������

//˳��������vector��̬����(�ڴ������������ȡ��ǰ�����ɾ�����������ٶȿ죬֧��������ʵ�����)
//			deque˫�����(�����ڴ������������ȡ���м����ɾ������ǰ���ٶȿ죬֧��������ʵ�����)
//			list˫������(�����������������ȡ�����ٲ���ɾ����֧��˫�������)

//����������set/multiset����(�ڲ�����ģ�ʹ��ƽ�������ʵ�֣�����ɾ���ͼ�������log(n)��֧��˫�������)
//			map/multimapӳ��(�ڲ���frist��С���������, frist��second�ֱ��ǵ�һ���͵ڶ���Ԫ��ֵ��֧��˫�������)


/*
˳�������͹����������õĳ�Ա������
begin()ָ���һ��Ԫ��
end()ָ�����һ��Ԫ�غ����λ��
rbegin()ָ�����һ��Ԫ��
rend()ָ���һԪ��ǰ���λ��
erase()ɾ��Ԫ�أ����ܻ�ʹ������ʧЧ
clear()ɾ������Ԫ��

˳���������õĳ�Ա������
front()���ص�һ��Ԫ�ص�����
back()�������һ��Ԫ�ص�����
push_back()�ں���������Ԫ��
pop_back()��ɾ�������Ԫ��
*/

//ע�⣺�����е�Ԫ�ض���ͨ�����Ƶķ�ʽ��ӵģ��������=��<�Ȳ��������������������㷨������


//����������stackջ(�Ƚ������top, bottom����ջ��ջ������top�ϲ���)
//			queue����(�Ƚ��ȳ���rear, front����ǰ������ں�����)
//			priority_queue���ȼ�����(�ڲ������ȼ�������)
//			bitset(λ����)

//��������˫�����������������������������������������

//sort�����㷨��binary_search���ֲ����㷨��Ҫ������ʵ�����
//find�����㷨���жϸ�����xС��y��yС��xͬʱ������������Ϊx����y��

/*
template<class InIt, class T>
InIt find(InIt first, InIt last, const T& val);
��������Χ[first, last)�в��ҵ���valֵ��Ԫ�أ�������last���㷨��Χ��������ҿ������䣻
����鵽������ָ��Ԫ�صĵ����������򷵻�last��

��ϵ���壺Ԫ�صĴ�С���ڹ�ϵ���ǳ���Ա�Զ���ģ�1��һ��С��2��Ҳ���Զ���1����2��
*/

using namespace std;

//�������ݽṹ
struct Student
{
	//string Name;  ֻ��ʹ�û������ͣ�����ʹ�ø����࣬��Ϊ��̬���������������ʱ���������
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
	//��ʼ������
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

	//ʹ��������������
	vector<Student> v(ss, ss+3);

	//ʹ�������㷨��������
	sort(v.begin(), v.end(), Cmp);	//����û��Cmp����ΪStudentû������<������

	//�������ݵ��������ļ�
	ofstream fSave("Student.txt", ios::out|ios::binary);
	if (!fSave) return 0;

	//������������
	vector<Student>::const_iterator citer;		//ʹ�õ��ǳ���������
	for(citer=v.cbegin();citer!=v.cend();citer++)
	{
		const Student &s = *citer;				//���ص��ǳ�������
		fSave.write((char *)(&s), sizeof(Student));
	}

	fSave.close();

	//�޸ĵ�����ѧ��������
	fstream fRead("Student.txt", ios::in|ios::out|ios::binary);

	fRead.seekp(sizeof(Student)*2, ios::beg);	//�ƶ��ļ�ָ��
	const char*szName = "GuiQuan";
	fRead.write(szName, strlen(szName)+1);	//���ȼ���1��д���ַ���������\0
	fRead.seekp(0, ios::beg);
	
	//��ȡ��������
	Student sRead;
	while(fRead.read((char *)(&sRead), sizeof(Student)))
	{
		cout<<setw(10)<<setiosflags(ios_base::left)<<setfill('*')<<sRead.Name;
		cout<<setw(10)<<setfill(' ')<<sRead.Age<<setw(10)<<sRead.Sorce<<endl;
	}

	fRead.close();

	return 0;
}


#pragma once

#include "Car.h"

/*public�̳��������Car����ֹ���ؼ̳�ʱ������μ̳е����⣬���ֶ��ͬ������
�̳з�ʽ�У�
	public��protected��private ���ʽ���
	virtual	�����
*/
class VolkswageCar: public virtual Car
{
public:
	VolkswageCar(void);

	virtual ~VolkswageCar(void);

	//��д����ĺ���
	virtual void Run(int mMile);

	//���ǻ���ĺ���
	void Show() const;

private:
	int mPrice;
	
	//������Ա��Ҫ�ڳ�ʼ���б��г�ʼ��
	const char *BRANDNAME;

	//��̬��Ա��Ҫ������ⲿ��ʼ��
	static int CREATEYEAR;
};

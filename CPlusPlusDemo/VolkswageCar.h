#pragma once

#include "Car.h"

/*public继承于虚基类Car：防止多重继承时出现绫形继承的问题，出现多个同名基类
继承方式有：
	public、protected、private 访问界限
	virtual	虚基类
*/
class VolkswageCar: public virtual Car
{
public:
	VolkswageCar(void);

	virtual ~VolkswageCar(void);

	//重写基类的函数
	virtual void Run(int mMile);

	//覆盖基类的函数
	void Show() const;

private:
	int mPrice;
	
	//常量成员需要在初始化列表中初始化
	const char *BRANDNAME;

	//静态成员需要在类的外部初始化
	static int CREATEYEAR;
};
